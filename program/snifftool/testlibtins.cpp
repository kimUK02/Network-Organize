#include <tins/tins.h>
#include <iostream>

using namespace std;
using namespace Tins;

int main(){
PacketSender sender("wlp2s0");
EthernetII pkt = EthernetII() / IP("192.168.0.3") / TCP() / RawPDU("foo");
sender.send(pkt); // send it through eth0 as well

std::cout << sender.default_interface().name() << std::endl;
sender.send(pkt); // now we're sending through eth1.
}