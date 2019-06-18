# Settings

## Server end (192.168.10.10)
1. Install the packages

        yum install nfs-utils

2. Create the shared directory

        mkdir /nfsfiles
        chmod -R 777 /nfsfiles

3. vi /etc/exports

        /nfsfiles   192.168.10.*    (rw, sync, root_squash)

4. restart the service

        systemctl restart rpcbind  # RPC, Remote Procedure Call, required by NFS
        systemctl enable rpcbind
        systemctl start nfs-server
        systemctl enable nfs-server
        ln -s '/usr/lib/systemd/system/nfs-server.service' '/etc/systemd/system/nfs.target.wants/nfs-server.service'

## Client end
1. Check the server

        showmount -e 192.168.10.10
            Export list for 192.168.10.10:
            /nfsfiles 192.168.10.*
        
2. mount the remote fs

        mkdir /nfs
        mount -t nfs 192.168.10.10:/nfsfiles /nfs
        
3. vi /etc/fstab

        192.168.10.10:/nfsfiles     /nfs        nfs     defaults    0   0
        
