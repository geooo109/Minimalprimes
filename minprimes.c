#include <stdio.h>
#define MAXNUMB 100000000
int main(){
	int i,j,z,m;/*i is the number we check if its a prime*/
	int digits,mask,mult,s,k;/*to calculate all the digits of the numb,to make binary,to make sunsequences,current subsequence*/
	int flag1,flag2,flag3,flag4;/*values 1 or 0*/

	/*start to checking the numbers*/
	for(i=11;i<=MAXNUMB;i+=2){/*starting from 11 beacause its the min(minimal) prime we want to check */
		z=i;
		flag1=1;/*to check every digit if its a prime or not*/

		/*start checking if one of the digits is prime*/
		while(z!=0&&flag1==1){
			if(z%10==2 || z%10==3 || z%10==5 || z%10==7){
				flag1=0;/*isnt a min prime*/
			}
			z/=10;
		}
		if(flag1==1){/*didnt found a prime digit*/

			digits=0;
			mult=1;
			z=i;

			/*check the subsequences first*/
			while(z!=0){
				z/=10;
				digits++;
			}

			/*calculate all multiplications with 2 for 2^d*/
			for(k=1;k<=digits;k++){
				mult*=2;
			}

			/*start creating all the subsequences we want to check*/
			/*using the technique with the mask*/
			for(k=1;k<mult-1;k++){
				s=0; /*current sunsequences*/
				mask=k;/*to make all the combinations with the binary*/
				m=1;/*to multiplie to make subsequences*/
				z=i;
				while(z!=0){
					if(mask%2==1){
						s+=(z%10)*m;
						m*=10;
					}
				z/=10;
				mask/=2;
				}

				/*now check if the subsequence is a prime*/
				flag2=1;/*for the loop and to check if is a prime*/
				flag3=1;/*subsequence  isnt a prime*/
				if(s%2==0 && s!=2){/* cant check it in the loop*/
					flag2=0;/*isnt a prime*/
				}
				if(s==1){/*must check it beacause 1 isnt a prime */
					flag2=0;
				}
				if(s%3==0){/*cant check it  in the loop*/
					flag2=0;/* isnt a prime */
				}
				for(j=5;j*j<=s&&flag2==1;j+=6){/*dividing by the numbers of the form  6j+1 and 6j-1 beacasue they are possible primes and i want to check only  if is divited with  primes(previous)  */
					if(s%j==0 || s%(j+2)==0){
						flag2=0;/*current sunsequence isnt a prime check the others*/
					}
				}
				if(flag2==1){
					flag3=0;/*we found a subsequence that is a prime*/
				}
				if(flag3==0){
					break;/*exit because we found a subsequence that is a prime */
				}
			}/*end of for loop that checks the subsequences*/

			/*now if flag3=1 we know that we didnt found any primes so we check the whole number*/
			if(flag3==1){
				flag4=1;/*for the loop to know if is a prime*/
				if(i%3==0){
					flag4=0;/*isnt a prime*/
				}
				for(j=5;j*j<=i && flag4==1;j+=6){/*same thing as the previous for*/
					if(i%j==0 || i%(j+2)==0){
						flag4=0;/*isnt a prime*/
					}
				}

				/*print i if is a minimal prime*/
				if(flag4==1){
					printf("%d\n",i);
				}
			}
		}
	}
return 0;
}

