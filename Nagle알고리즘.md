# Nagle 알고리즘 #

Nagle 알고리즘은 네트워크상에서 돌아다니는 패킷들의 흘러 넘침을 막기 위해서 1984년에 제안된 알고리즘이다.

기본적으로 TCP소켓은 Nagle 알고리즘을 적용해서 데이터를 송수신한다. 때문에 ACK가 수신될 때까지 최대한 버퍼링을 해서 데이터를 전송한다.

네트워크의 효율적인 사용을 위해서 Nagle 알고리즘을 반드시 적용해야 한다.

그러나 Nagle 알고리즘이 항상 좋은 것은 아니다. 전송하는 데이터의 특성에 따라서 Nagle 알고리즘의 적용 여부에 따른 트래픽의 차이가 크지 않으면서도 Nagle 알고리즘을 적용하는 것보다 데이터의 전송이 빠른 경우도 있다. '용량이 큰 파일 데이터의 전송'이 대표적인 예이다. 파일 데이터를 출력버퍼로 밀어 넣는 작업은 시간이 걸리지 않은다. 때문에 Nagle 알고리즘을 적용하지 않아도 출력버퍼를 거의 꽉 채운 상태에서 패킷을 전송하게 된다. 따라서 패킷의 수가 크게 증가하지도 않을 뿐더러, ACK를 기다리지 않고 연속해서 데이터를 전송하니 전송속도도 놀랍게 향상된다.

## Nagle 알고리즘의 중단 ##

Nagle 알고리즘의 적용 여부에 따른 트래픽의 차이가 크지 않으면서도 Nagle 알고리즘을 적용하는 것보다 데이터의 전송이 빠른 경우.

소켓옵션 TCP_NODELAY 를 1(TRUE)로 변경
	
### setsockopt ###

	int opt_val = 1;
	setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (void*)&opt_val, sizeof(opt_val));

### getsockopt ###

	int opt_val;
	socklen_t opt_len;
	opt_len = sizeof(opt_val);
	getsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (void*)&opt_val, &opt_len);

- Nagel 알고리즘이 설정된 상태라면 함수호출의 결과로 변수 opt_val에는 0이 저장되며, 반대로 설정되지 않은 상태라면 1이 저장된다.

