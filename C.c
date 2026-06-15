// 놀이동산 요금 계산
// 조건문, 논리연산자

#include <stdio.h>

int main() {
  int iage;   // 나이를 담을 변수
  int iprice = 10000;   // 기본 요금 10000원

  printf("나이: ");
  scacnf("%d\n", &iage);

  if ((iage <= 7) || (iage == 20) || (iage >= 65));
    iprice = 0;
  else if ((iage <= 13) || (iage >= 50) && (iage <= 59))
    iprice = iprice - (iprice * 0.3); // 30% 할인
  else
    iprice = 10000;

pirntf("요금: %d\n", iprice);
return 0;
}


// 세 정수 중 최댓값 찾기
#include <stdio.h>

int main() {
  int num1, num2, num3;

  printf("세 개의 정수 입력: ");
  scanf("%d %d %d", &num1, &num2, &num3);

// 첫번째 조건: num1이 나머지 둘보다 크면 -> num1이 최댓값
  if ((num1 > num2) && (num1 > num3)) {
    printf("%d가 가장 큽니다.\n", num1);
  }
// 두번째 조건: num2가 나머지 둘보다 크면 -> num2가 최댓값
  else if ((num2 > num1) && (num2 > num3)) {
    printf("%d가 가장 큽니다.\n", num2)
  }
// 세번째 조건: 위 조건 모두 충족 x -> num3가 최댓값
  else {
      printf("%d가 가장 큽니다.\n", num3);
  }
    return 0;
}

// 범위 합 구하기 (while)
#include <stdio.h>

int main() {
  int isum = 0;  // 합계 저장소, 반드시 0으로 초기화 후 시작
  int istart, iend, i;

  printf("시작 정수와 종료 정수 입력: ");
  scanf("%d %d", &istart, &iend);

  i = istart; // i를 시작값으로 설정

  while(i <= iend) {  // i가 종료값 이하인 동안만 반복
      isum = isum + i;  // 누적 합산: isum에 i를 계속 더함
      if (i < iend)
        printf("%d + ", i);  // 마지막 숫자 전에는 '+' 출력
      else
        printf("%d = ", i);  // 마지막 숫자에는 '=' 출력
      i++;                // i를 1씩 증가 (이게 없으면 무한 루프)
  }
  printf("%d\n", isum);
  return 0;

// for문 구조
// while의 초기식, 조건식, 증감식을 한 줄로 압축한 형태
// for (초기식; 조건식; 증감식); {
    // 반복할 내용
//  }
// for (int i = 1; i <= 9; i++) 이 구조 중요

// 구구단 (for)
#include <stdio.h>

int main() {
  int dan;
  printf("몇 단을 출력할까요?: ");
  scanf("%d", &dan);

  // i가 1부터 9까지 -> 9번 반복
  for (int i = i; i <= 9; i++) {
    printf("%d x %d = %d\n", dan, i, dan*i);
  }
  return 0;
}

// 중첩 for문을 사용해 구구단 표를 만들자
#include <stdio.h>

int main() {
    int i, j, isum;

    // 바깥 for: i가 2→5→8 (3씩 증가) — 단을 3개씩 묶음
    for (i = 2; i < 10; i = i + 3) {

        // 안쪽 for: j가 1~9 — 각 묶음의 1단부터 9단까지
        for (j = 1; j < 10; j++) {
            // 가로 한 줄에 3개의 단을 나란히 출력
            isum = i * j;
            printf("%d * %d = %d\t", i, j, isum);       // 예: 2단
            isum = (i + 1) * j;
            printf("%d * %d = %d\t", (i + 1), j, isum); // 예: 3단
            isum = (i + 2) * j;
            printf("%d * %d = %d\n", (i + 2), j, isum); // 예: 4단
        }
        printf("\n"); // 묶음 간 빈 줄
    }
    return 0;
}
// 설계 핵심: i를 3씩 늘리고, i·i+1·i+2를 한 줄에 찍으면 3단씩 가로 정렬됨


// 종합 성적 프로그램 (for + while 중첩)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>  // strcpy() 사용을 위해 필요

int main() {
    int inn, ikor, ieng, imath, ihap = 0;
    int i;
    float favg;
    char cgrade;
    char shak[20]; // 추천학과 문자열 (배열로 선언, 최대 19글자)

    printf("학생 수: ");
    scanf("%d", &inn);

    for (i = 1; i <= inn; i++) { // 학생 수만큼 반복

        // 입력 검증: 0~100 범위 벗어나면 재입력 요구
        while (1) {  // while(1) = 무한 반복, 조건 만족 시 break로 탈출
            printf("[%d]국어, 영어, 수학: ", i);
            scanf("%d %d %d", &ikor, &ieng, &imath);
            if ((ikor >= 0 && ikor <= 100) &&
                (ieng >= 0 && ieng <= 100) &&
                (imath >= 0 && imath <= 100))
                break; // 정상 범위면 while 탈출
        }

        ihap = ikor + ieng + imath;
        favg = (float)ihap / 3; // (float) 형변환: 정수/정수=정수이므로, 소수점 얻으려면 강제 변환

        // 학점 계산 (평균 기준)
        if (favg >= 90)      cgrade = 'A';
        else if (favg >= 80) cgrade = 'B';
        else if (favg >= 70) cgrade = 'C';
        else if (favg >= 60) cgrade = 'D';
        else                 cgrade = 'F';

        // 추천학과 계산
        if (favg >= 60 && (ikor >= 80 || ieng >= 70))
            strcpy(shak, "문과");     // strcpy: 문자열을 shak에 복사
        else if (favg >= 50 && imath >= 80)
            strcpy(shak, "이과");
        else if (ikor >= 70 && ieng >= 90)
            strcpy(shak, "외국어과");
        else
            strcpy(shak, "없음");

        printf("----------[%d] 성적표----------\n", i);
        printf("국어 : %d\n", ikor);
        printf("영어 : %d\n", ieng);
        printf("수학 : %d\n", imath);
        printf("합계 : %d\t평균 : %.2f\t학점 : %c\n", ihap, favg, cgrade);
        printf("추천학과 : %s\n\n", shak); // %s: 문자열 출력
    }
    return 0;
}

// 함수로 계산기 만들기
#include <stdio.h>
#include <stdlib.h>

// 정수 연산 함수 — +,-,* 처리
// 매개변수: 정수1, 연산자 문자, 정수2 를 받아서 결과값(int)을 돌려줌
int cal(int num1, char oper, int num2) {
    int isum;
    if (oper == '+') isum = num1 + num2;
    if (oper == '-') isum = num1 - num2;
    if (oper == '*') isum = num1 * num2;
    return isum; // 계산 결과를 호출한 곳으로 돌려줌
}

// 나누기 전용 함수 — 결과가 소수일 수 있으므로 float 반환
float fcal(int num1, char oper, int num2) {
    return (float)num1 / num2; // num1을 float으로 변환해야 소수점 나옴
}

int main(int argc, char *argv[]) {
    int inum1, inum2, isum;
    char oper;
    float fdiv;

    printf("2수 입력 (정수 연산자(+,-,*,/) 정수): ");
    scanf("%d %c %d", &inum1, &oper, &inum2); // 예) 10 + 3

    if (oper == '/') {
        fdiv = fcal(inum1, oper, inum2);          // 나누기는 fcal 호출
        printf("%d %c %d = %.2f\n", inum1, oper, inum2, fdiv);
    } else {
        isum = cal(inum1, oper, inum2);            // 나머지는 cal 호출
        printf("%d %c %d = %d\n", inum1, oper, inum2, isum);
    }
    return 0;
}
// 설계 핵심: 연산 로직을 함수로 분리 → main은 입출력만 담당, 깔끔!


// 성적표 최종: 배열 + 함수 + 석차
#include <stdio.h>
#include <stdlib.h>

// 학점 계산 함수 — 평균을 받아서 학점 문자를 돌려줌
char cgrade(float favg) {
    char cg;
    if (favg >= 90)      cg = 'A';
    else if (favg >= 80) cg = 'B';
    else if (favg >= 70) cg = 'C';
    else                 cg = 'F';
    return cg;
}

void main() {
    int ikor[5], ieng[5], imath[5];
    int isum[5], irank[5]; // irank: 각 학생의 석차
    float favg[5];
    char grade[5]; // 각 학생의 학점 문자
    int i, j;

    // 입력 + 기본 계산
    for (i = 0; i < 5; i++) {
        printf("[%d] 국어, 영어, 수학: ", i + 1);
        scanf("%d %d %d", &ikor[i], &ieng[i], &imath[i]);
        isum[i]  = ikor[i] + ieng[i] + imath[i];
        favg[i]  = (float)isum[i] / 3;
        grade[i] = cgrade(favg[i]); // 함수 호출해서 학점 저장
        irank[i] = 1; // 석차 초기값: 1등으로 시작
    }

    // 석차 알고리즘 — 이중 for문
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            // i번 학생의 합계가 j번 학생보다 작으면 → i의 등수가 밀림
            if (isum[i] < isum[j])
                irank[i]++; // 나보다 점수 높은 사람이 한 명 더 있다는 뜻 → 등수+1
        }
    }
    // 예) A=240, B=200, C=180 이면:
    // A: 자기보다 높은 사람 0명 → 1등
    // B: A만 자기보다 높음 → 2등
    // C: A,B 둘 다 높음 → 3등

    // 출력
    printf("번호\t국어\t영어\t수학\t합계\t평균\t학점\t석차\n");
    for (i = 0; i < 5; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%.2f\t%c\t%d\n",
               i+1, ikor[i], ieng[i], imath[i], isum[i], favg[i], grade[i], irank[i]);
    }
}



