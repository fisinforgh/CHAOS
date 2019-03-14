#!/bin/bash
echo "For continue the uninstallation, you need to be root user!"
sudo rm -r /usr/share/Chaos_V0.1
sudo rm /usr/bin/Chaos
sudo rm ~/.local/share/applications/Chaos.desktop
echo "Finished uninstallation!"
