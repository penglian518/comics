# Configurations files

    /etc/dhcp/dhcpd.conf
    
# Settings
1. vi /etc/dhcp/dhcpd.conf

        ddns-update-style none;
        ignore client-updates;
        subnet 192.168.10.0 netmask 255.255.255.0 { 
            range 192.168.10.50 192.168.10.150;
            option subnet-mask 255.255.255.0; 
            option routers 192.168.10.1;
            option domain-name "linuxprobe.com"; 
            option domain-name-servers 192.168.10.1; 
            default-lease-time 21600; 
            max-lease-time 43200;
        }
        
        # for fixing IP
        host linuxprobe {
            hardware ethernet 00:0c:29:27:c6:12;
            fixed-address 192.168.10.88;
        }
        
2. restart dhcpd and make it auto launch

        systemctl start dhcpd
        systemctl enable dhcpd
        ln -s '/usr/lib/systemd/system/dhcpd.service' '/etc/systemd/system/multi-user.target.wants/dhcpd.service'

