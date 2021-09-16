# debughidevent
small software to make linux hid events human readable

## installing on ubuntu/debian

* download the [latest release](https://github.com/Apfelwurm/debughidevent/releases) (most likely x64, for Raspberry use armhf)
* open your cli in the download folder and run:
```
sudo dpkg -i debughidevent_*.deb
```

## uninstalling on ubuntu/debian

* open your cli and run:
```
sudo dpkg -r debughidevent
```
## prerequirements for building on debian

* cmake
* build-essential

## building on ubuntu/debian

* install the prerequirements above
* clone this repository
```
git clone https://github.com/Apfelwurm/debughidevent.git
```

To build the usable deb package, you have to go to the debughidevent and run:
```
./rebuild.sh
```

To build the software and just run it for development purposes or a single time, you have to go to the debughidevent and run:
```
./rebuild_dev.sh /dev/input/eventXX
```
Note: It currently has to run as root to access the hid

## detect hardware

To list all hid devices, run:
```
sudo cat /proc/bus/input/devices
```

Then you have to identify the device that you are using either by name or the product/ vendor id. Then you have to look for the ``Handlers`` key, there should be at least an ``eventXX`` in the value.  
If you find multiple entrys for your device, try them one after the other.

To get the output of your hid parsed, install [debughidevent](https://github.com/Apfelwurm/debughidevent) and run (replace XX with the numbers you found out in the last step):
```
sudo /usr/bin/debughidevent /dev/input/eventXX
```

now turn / press the knob and you should get a output like this:
```
key detected: Keycode 4 , value 786665, type 4, time 1631045266
key detected: Keycode 115 , value 1, type 1, time 1631045266
key detected: Keycode 0 , value 0, type 0, time 1631045266
key detected: Keycode 4 , value 786665, type 4, time 1631045266
key detected: Keycode 115 , value 0, type 1, time 1631045266
key detected: Keycode 0 , value 0, type 0, time 1631045266
```


## contributions

if you want to contribute to the project or if you have problems, dont hesitate to open issues or submit pull requests.


