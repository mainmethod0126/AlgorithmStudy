// AlgorithmStudy_01Week_WSSs_Quiz.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include "stdlib.h"
#include "algorithm"
#include "windows.h"
#include <vector>
#include <iostream>

void solution(std::vector<std::vector<int>>& nVectInput);

int main()
{
    std::cout << "Hello World!\n"; 
	
	/*int nSizeX = 6;
	int nSizeY = 11;
*/
	//std::vector<std::vector<int> > arr(nSizeY, std::vector<int>(nSizeX, 0));


	// 2019-01-14 wssin
	// 이차원 벡터 선언 및 초기화
	// 솔루션 함수 검증을 위한 입력 값 셋팅.
	// 입력 예시 1번
	std::vector< std::vector<int> > nVectInput1{
		{5},
		{1, 4},
		{4, 3, 3, 2, 1},
		{5, 2, 4, 3, 2, 1},
		{4, 4, 3, 3, 1},
		{4, 3, 2, 1, 1},
		{4, 2, 3, 2, 1},
		{4, 4, 3, 2, 1},
		{3, 4, 3, 2},
		{5, 4, 4, 2, 3, 1},
		{5, 4, 2, 4, 1, 3}
	};

	// 입력 예시 2번
	std::vector< std::vector<int> > nVectInput2{
		{4},
		{4, 4, 3, 2, 1},
		{4, 1, 4, 3, 2},
		{4, 3, 3, 2, 1},
		{4, 4, 3, 3, 3},
		{4, 4, 3, 3, 3},
		{4, 3, 4, 3, 2},
		{4, 3, 2, 1, 1},
		{3, 3, 2, 1}
	};

	solution(nVectInput2);
}

void solution(std::vector<std::vector<int>>& nVectInput)
{
	// 2019-01-14 wssin
	// v[0][0]을 제외한 v[1][0] 부터 시작하여
	// v[N][1]부터 v[N][Length] 까지 정렬
	// std::sort는 퀵소트 기반
	for (int AxisY = 1; AxisY <= nVectInput[0][0] * 2; AxisY++)
	{
		std::sort(nVectInput[AxisY].begin() + 1, nVectInput[AxisY].end(), std::greater<int>());
	}

	// 정렬이 완료되었으니 이제 비교문 추가하면 됨.
	for (int AxisY = 1; AxisY <= nVectInput[0][0] * 2; AxisY += 2)
	{
		int nIter = 0;

		// 2019-01-15 wssin
		// 비교할 두 열의 길이를 비교하여 작은놈으로 반복자 선택
		// 이유. 한놈이 더 길거나 짧을 경우 한놈의 길이를 AxisX로하여 비교하면 널포인트 익셉션 발생
		// 그렇기에 작은놈으로 비교하고 어차피 작은 놈의 마지막 까지 비교했는데
		// 아직 게임이 안끝났으면 작은놈이 진거임.
		// 예를 들어
		// A : 4, 3, 3, 2, 1
		// B : 4, 3, 3, 2
		// 두 입력에서
		// 길이가 작은 B의 길이를 기준으로 비교횟수를 설정하고 비교하였을 시
		// B의 마지막인 4번째 까지 비교했는대도 동점이다.
		// A의 나머지 숫자가 뭔지 생각할 필요도 없지
		nVectInput[AxisY][0] >= nVectInput[AxisY + 1][0] ? nIter = nVectInput[AxisY + 1][0] : nIter = nVectInput[AxisY][0];

		for (int AxisX = 1; AxisX <= nIter; AxisX++)
		{
			// A가 크면
			if (nVectInput[AxisY][AxisX] > nVectInput[AxisY + 1][AxisX])
			{
				std::cout << "A\n";
				break;
			}
			
			// B가 크면
			else if (nVectInput[AxisY][AxisX] < nVectInput[AxisY + 1][AxisX])
			{
				std::cout << "B\n";
				break;
			}

			// 마지막까지 돌았는데도 승패가 갈리지 않았다면
			if (AxisX == nIter)
			{
				// 2019-01-15 wssin
				// 각 라인 0번 인덱스는 그 라인의 도형 갯수
				// 그러니까 아직 승패가 갈리지 않았다면
				// 누가 더 큰지 비교해봐서
				// 더 큰놈이 이기고
				// 만약 크기가 같다면
				// 드로우
				if (nVectInput[AxisY][0] > nVectInput[AxisY + 1][0])
				{
					std::cout << "A\n";
					break;
				}
				else if (nVectInput[AxisY][0] < nVectInput[AxisY + 1][0])
				{
					std::cout << "B\n";
					break;
				}
				else
				{
					std::cout << "D\n";
					break;
				}
			}
		}
	}
}


/*
	2019-01-15 wssin
	영단어 외워야하는데... 내일 토익학원 시험인대..
	안외웠다고 또 혼나겠다..
*/


// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
