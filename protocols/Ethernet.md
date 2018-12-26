# Ethernet
LAN(Local Area Network)의 규격

> OSI 7계층에서 **MAC Address** 주소로 통신하는 방식


##  CSMA/CD 
> Carrier Sense Multiple Access with Collision Detection
>> 반송파 감지 다중 접속 및 충돌 탐지

1. 네트워크를 사용하려는 컴퓨터가 
    
    현재 네트워크 위에 있는 데이터가 있는지 감지 .
    
2.  현재 다른 데이터가 전송 중이면 사용할 수 있을 때까지

    기다리고 아니면 전송을 시작한다.
3. 여러 군데에서 동시에 전송을 시작해 충돌이 발생하면 최소 
    패킷 시간 동안 전송을 계속해, 

    다른 컴퓨터가 충돌을 탐지할 수 있도록 한다.

4. 임의 시간 동안 기다린 뒤에 다시 **신호** (반송파)를 감지하고,

     네트워크 사용자가 없으면 전송을 다시 시작한다.
5. 전송을 마치면, 상위 계층에 전송이 끝났음을 알리고 끝마친다.

    여러 번 다시 시도했음에도 전송에 실패하면 이를 상위 계층에 알리고 끝마친다.
---
>  오늘날에는 대부분 **이더넷** 스위치를 사용하여 
>
> 스위치 방식의 네트워크(switched network)를 구성하는데,
>
> 이 경우 충돌이 일어나지 않는다.

## Ethernet frame

![Ethernet](./imgs/ethernetframe.png)
Preamble: 0과1을 반복하여 수신기를 준비시키기위한 것

SFP: 1 바이트 짜리의 비트열(10101011)
- SFD 비트열부터는 바이트 단위로 구성되어 있다는 
     사실을 알리는 프레임 동기용 비트열 임
- 마지막 2개의 연속된 1, 즉 11 에 의해 프레임의 시작을 수신기가 알게됨

Destination : Destination의 MAC주소

Source : Source의 MAC주소

EtherType: 뒤에올     https://en.wikipedia.org/wiki/EtherType#Examples

Payload:보낼 data

FCS: 데이터의 에러검출을 위한 [*CRC*](http://www.ktword.co.kr/abbr_view.php?nav=&m_temp1=603&id=744) 코드이다.



