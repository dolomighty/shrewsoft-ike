
### revisione shrewsoft IKE per renderlo compatibile con le recenti release di openssl+qt+whatever
esteso dal fork di ...

stato al 2022-02-25 10:43:32
```
ikec ok
iked ok
qikec ok
```


compile+install
```
cmake -DCMAKE_INSTALL_PREFIX=/usr -DQTGUI=YES -DETCDIR=/etc -DNATT=YES
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
05354+OTP


sudo route add -net 10.0.0.0/8 tap0
sudo route add -net 172.16.0.0/12 tap0
sudo route add -net 156.0.0.0/8 tap0
sudo route del -net 0.0.0.0/0 tap0
sudo route -n
```





ikec genera questo albero
```
find /home/dmy/.ike/ -type f
```
