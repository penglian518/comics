# TigerVNC Server on Ubuntu 20.04

## Install TigerVNC

    sudo apt install tigervnc-standalone-server
    
    vncpasswd
    vncserver -list
    vncserver -localhost no :1
    vncserver -kill :1
    
## Configure the VNC Server

Create user config file

    vi ~/.vnc/xstartup


    #!/bin/sh

    test x"$SHELL" = x"" && SHELL=/bin/bash
    test x"$1"     = x"" && set -- default

    vncconfig -iconic &
    "$SHELL" -l << EOF
    export XDG_SESSION_TYPE=x11
    export GNOME_SHELL_SESSION_MODE=ubuntu
    dbus-launch --exit-with-session gnome-session --session=ubuntu
    EOF
    vncserver -kill $DISPLAY


Change permission

    chmod 755 xstartup

Create system service file

    sudo vi /etc/systemd/system/vncserver@.service
    
    [Unit]
    Description=Start TigerVNC server at startup
    After=syslog.target network.target

    [Service]
    Type=simple
    User=USERNAME
    PAMName=login
    PIDFile=/home/USERNAME/.vnc/%H:%i.pid
    ExecStartPre=/usr/bin/vncserver -kill :%i > /dev/null 2>&1
    ExecStart=/usr/bin/vncserver -fg -depth 24 -geometry 1920x1200 -localhost no :%i
    ExecStop=/usr/bin/vncserver -kill :%i

    [Install]
    WantedBy=multi-user.target

Start the service

    sudo systemctl daemon-reload
    sudo systemctl enable vncserver@1.service
    sudo systemctl start vncserver@1
    sudo systemctl status vncserver@1


# Reference
https://www.sproutworkshop.com/2021/04/how-to-create-a-virtual-headless-tigervnc-server-on-ubuntu-20-04/

