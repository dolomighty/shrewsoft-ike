
### Shrewsoft IKE

aggiornato per ubuntu 22



compile+install
```
sudo apt install \
build-essential \
libssl-dev      \
libedit-dev     \
*qt5*dev        \
cmake           \
bison           \
flex

cmake -DCMAKE_INSTALL_PREFIX=/usr -DQTGUI=YES -DETCDIR=/etc -DNATT=YES .

make && sudo make install
```

iked, il servizio ipsec vero e proprio, deve essere attivo perché ikec/qikea/qikec possano funzionare  

```
sudo pkill -f iked
#sudo iked -F -d 6    # debug
sudo iked	          # normale (demone)

```

il file script/linux/nm/ike-routes è uno script per network manager    
fa si di installare automaticamente delle rotte quando il tunnel sale  
i privati andranno sul tunnel, i pubblici useranno il normale routing di casa  
va copiato in /etc/NetworkManager/dispatcher.d/  

```
sudo cp script/linux/nm/ike-routes /etc/NetworkManager/dispatcher.d/
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

