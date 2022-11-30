#include <stdio.h> //printf
#include <stdlib.h> //exit
#include <string.h> // strlen
#include <unistd.h> //fork

int main(void)
{
	char command[1000]; //commnad 배열 1000개 선언
	char executingList[10][1000]; // 10행 1000열의 executingList 배열을 선언
	char *executingListPtr[10]; // 포인터 선언
	int pid;
	while (1) //while문 실행
	{
		char currWorkingDir[2048]={0,}; //currWorkingDir 배열 2048개 선언하고 처음에 0넣음
		getcwd(currWorkingDir, sizeof (currWorkingDir)); //현재작업디렉토리의 경로를 currWorkingDir에 currWorkingDir사이즈만큼저장
		printf("[\033[1m\033[40;32mMy_Shell\033[0m] \033[40;36m%s$\033[0m ",currWorkingDir);	//Jaemin: 이 라인은 굳이 주석을 달 필요 없음.

		fgets(command, sizeof(command), stdin);  //입력한 문자들을 command에 저장하고 성공하면 command를 리턴
        command[strlen(command)-1]=0; //command [999] = 0
        //gets(command);	
		char *ptr = strtok(command," ");  //command문자열 공백을기준으로 자르고(나누고) ptr배열에 넣는다
		if (ptr == NULL) continue;	// ptr이 NULL이면 계속진행
		
		printf ("StrTok:%s\r\n",ptr); //Strtok : ptr에들어있는 문자를 출력
		strcpy(executingList[0],ptr);	// ptr 을 executingList[0]에 복사한다
		executingListPtr[0]=&executingList[0][0]; //executingList[0]의 주소는 executingList 0행0열이다.

		for (int numberOfToken=1;numberOfToken<10;numberOfToken++) //numberOfToken이 1이고 10이 될때까지 1씩증가
		{
			ptr = strtok(NULL," "); //NULL문자열 공백을 기준으로 나누고 ptr에 넣는다
			if (ptr == NULL) //ptr 이 NULL 이면 실행
			{
				executingListPtr[numberOfToken] = NULL; // executingListPtr[numberOfToken] 이 NULL
				break;	//if문 탈출
			}
			strcpy(executingList[numberOfToken],ptr); //ptr을 executingList[numberOfToken]에서 지정한 위치로 복사
			executingListPtr[numberOfToken] = &executingList[numberOfToken][0]; //executingList[numberOfToken][0]주소를 executingListPtr[numberOfToken]에 대입
		}	

		for (int numberOfToken=0;numberOfToken<10;numberOfToken++)	//numberOfToken이 0이고 10이 될때까지 1씩증가
		{
			if (executingListPtr[numberOfToken]!=NULL) //executingListPtr[numberOfToken] 이 NULL이 아니면 if문 실행
			{
				printf ("Tok %d->[%s]\r\n",numberOfToken, executingListPtr[numberOfToken]); // numberOfToken에 들어있는 숫자출력, executingListPtr[numberOfToken] 문자열출력
			}
			else //executingListPtr[numberOfToken] 이 NULL이면 밑에실행
			{
				break; //for문 탈출
			}
			
		}


		if (strcmp(executingListPtr[0],"도움")==0) //executingListPtr[0]이 도움이면 if문실행 (두개를비교)
		{
			printf ("도움말... 은 man 명령어를 실행시켜 보든지 말든지\r\n"); //" " 안에 내용 출력
			printf ("종료는 quit \r\n"); //" " 안에 내용출력
			continue; //계속
		}
		else if (strcmp(executingListPtr[0],"quit")==0) //executingListPtr[0]이 quit이면 elseif 문실행
		{
			printf ("임베디드시스템은 재미있어요!\r\n"); // " " 안에 내용출력
			break; // if문 탈출
		}

		/*여기서 부터*/
		else if (strcmp(executingListPtr[0],"help")==0) 
		{
			printf ("'--help'를 입력하면 목록이 보입니다.\r\n"); 
			continue; //계속
		}

        else if (strcmp(executingListPtr[0], "ls") == 0) 
        {
            if ((pid = fork()) == 0) {
            if
               (execlp("ls", "ls", (char *)0));{
               exit(0);
            }
         }
         if (pid > 0) {
            wait(NULL);
        }
        } 

        else if (strcmp(executingListPtr[0], "ps") == 0) 
        {
            if ((pid = fork()) == 0) {
            if 
               (execlp("ps", "ps", (char *)0));{
               exit(0);
            }
         }
         if (pid > 0) {
            wait(NULL);
        }
        }
		
        else if (strcmp(executingListPtr[0], "pwd") == 0) 
        {
            if ((pid = fork()) == 0) {
            if 
               (execlp("pwd", "pwd", (char *)0));{
               exit(0);
            }
         }
         if (pid > 0) {
            wait(NULL);
        }
        }

        else if (strcmp(executingListPtr[0], "who") == 0) 
        {
            if ((pid = fork()) == 0) {
            if 
               (execlp("who", "who", (char *)0));{
               exit(0);
            }
         }
         if (pid > 0) {
            wait(NULL);
        }
        }

		else if (strcmp(executingListPtr[0], "cd") == 0) {
         char cdPath[256] = ".";
         
         if (executingListPtr[1] != NULL) {
            strcpy(cdPath, executingListPtr[1]);
         }
         
         int ret = chdir(cdPath);
         if (ret < 0) {
            printf("cd 경로 오류 발생 :%s\n", cdPath);
            continue;
         }
         getcwd(currWorkingDir, sizeof(currWorkingDir));
         
      }

		
		/*여기까지 채워 넣으세요*/
	}
	printf ("진짜로 재미있어요!\r\n");
	return 1;
}

