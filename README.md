
### Shrewsoft IKE

aggiornato per ubuntu 22



compile+install
```
sudo apt install \
libssl-dev  \
libedit-dev \
flex        \
bison       \
*qt5*dev

cmake -DCMAKE_INSTALL_PREFIX=/usr -DQTGUI=YES -DETCDIR=/etc -DNATT=YES .

make && sudo make install
```

iked, il servizio ipsec vero e proprio, deve essere attivo  

```
sudo pkill -f iked
#sudo iked -F -d 6    # debug
sudo iked	          # normale (demone)

```


le due conf usate in tim sono sotto sites  
cmq si possono creare con qikea

```
mkdir -p ~/.ike/sites
cp -f sites/* ~/.ike/sites
```


ikec si può lanciare in modo interattivo e non (utile per scripts in cli)

interattivo
```
qikec -a -r EXTDACON@dacvpn -u TELECOMITALIA\00519575

verrà chiesta una pass (l'OTP di TIM Secure APP)
```

non interattivo
```
qikec -n -a -r EXTDACON@dacvpn -u TELECOMITALIA\00519575 -p 12345 (l'OTP di TIM Secure APP)
```


se tutto va bene, sarà apparsa un'interfaccia tap0   
in automatico il default gateway punta a quella   
io preferisco ritoccare la cosa, faccio si che i privati vadan sul tunnel
ed i pubblici usino il routing di casa

```
sudo ip route add 10.0.0.0/8    dev tap0
sudo ip route add 172.16.0.0/12 dev tap0
sudo ip route add 156.0.0.0/8   dev tap0
sudo ip route del 0.0.0.0/0     dev tap0
sudo ip route | column -t
```


