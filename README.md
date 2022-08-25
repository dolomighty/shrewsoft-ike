
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
sudo apt install libssl-dev libedit-dev flex bison

cmake -DCMAKE_INSTALL_PREFIX=/usr -DQTGUI=NO -DETCDIR=/etc -DNATT=YES .
make && sudo make install
```



debug
```
pkill -f iked
sudo iked -F -d 6
```





uso normale
```
pkill -f iked
sudo iked

qikec -r EXTDACON@dacvpn -u TELECOMITALIA\00519575

pass
OTP da TIM Secure APP


sudo ip route add 10.0.0.0/8    dev tap0
sudo ip route add 172.16.0.0/12 dev tap0
sudo ip route add 156.0.0.0/8   dev tap0
sudo ip route del 0.0.0.0/0     dev tap0
sudo ip route
```





ikec genera questo albero
```
find /home/dmy/.ike/ -type f
```
