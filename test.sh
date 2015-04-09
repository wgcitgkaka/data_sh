#!/bin/bash
ip="1.2.3.4"

function ipnum10to2(){
	   num10=$1
		      num2=`echo "obase=2;$num10"|bc`
		         num2len=`echo $num2|wc -c`
			    while [ $num2len -le 8 ]
				       do
					             num2="0"$num2
							           num2len=`echo $num2|wc -c`
								      done
								         echo $num2
}

function ip10to2(){
	   ip=$1
		      read -a ipsub <<< ${ip//./ };
	      for num in {0..3}
	         do
			       ip2=$ip2`ipnum10to2 ${ipsub[$num]}`
				          done
					     echo $ip2
}

result=`ip10to2 $ip`
echo $result
