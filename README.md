
### revisione shrewsoft IKE per renderlo compatibile con le recenti release di openssl+qt+whatever

esteso dal fork di ...

stato al 2022-08-25 23:05:27
```
ikec ok
iked ok
qikec nok (qt4 non più installabili, va portato a qt5+)
```


compile+install
```
sudo apt install \
libssl-dev \
libedit-dev \
flex \
bison

cmake -DCMAKE_INSTALL_PREFIX=/usr -DQTGUI=NO -DETCDIR=/etc -DNATT=YES .
make && sudo make install
```

vengono prodotti ikec e iked   
-ikec è il client locale, legge le info di auth e le conf, parla con iked   
-iked è il demone (simile ad ipsec) che gestisce i tunnel veri e propri  

iked si può lanciare in debug o normale:   

debug
```
pkill -f iked
sudo iked -F -d 6
```

normale
```
pkill -f iked
sudo iked
```


ikec ha bisogno dei files di conf per lavorare, oltre alle credenziali   
sotto sites ne ho messi due   

```
mkdir -p ~/.ike/sites
cp -f sites/* ~/.ike/sites
```


ikec si può lanciare in modo interattivo, in cui accetta dei comandi (le gui usano questa modalità)
oppure non-interattivo, utile per scripts in cli

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




