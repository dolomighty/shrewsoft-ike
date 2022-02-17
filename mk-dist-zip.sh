#!/bin/bash
make && sudo make install
rm -f ike.zip
zip ike.zip \
/etc/iked.conf \
/usr/bin/ikec \
/usr/lib/libss_idb.so \
/usr/lib/libss_idb.so.2.2.1 \
/usr/lib/libss_ike.so \
/usr/lib/libss_ike.so.2.2.1 \
/usr/lib/libss_ip.so \
/usr/lib/libss_ip.so.2.2.1 \
/usr/lib/libss_ith.so \
/usr/lib/libss_ith.so.2.2.1 \
/usr/lib/libss_log.so \
/usr/lib/libss_log.so.2.2.1 \
/usr/lib/libss_pfk.so \
/usr/lib/libss_pfk.so.2.2.1 \
/usr/local/man/man1/ikec.1 \
/usr/local/man/man5/iked.conf.5 \
/usr/local/man/man8/iked.8 \
/usr/sbin/iked \

