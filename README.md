# wireshark-in-C-with-TCPdump
Projet TSR analyser of the network like wireshark
only wrok on ubuntu because some library give by ubuntu

fo install:

sudo apt-get install libpcap0.8-dev
make

fo use it:

./analyse

parameters:
-i <interface>  : interface analyse (default: the interface conected to the web)  
-o <file>  : file .pcap to analyse 
-f <filter>  : filtre BPF between "" (example of filter https://biot.com/capstats/bpf.html) (optionnel)
-v <1..3> :  level of verbosity (1=one line by packet ; 2=one line by protocol ; 3=complete;  default:1)

you can use in same time -i and -o
