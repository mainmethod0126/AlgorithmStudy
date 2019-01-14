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
	std::vector< std::vector<int> > nVectInput{
		{5 ,0, 0, 0, 0, 0},
		{1, 4, 0, 0, 0, 0},
		{4, 3, 3, 2, 1, 0},
		{5, 2, 4, 3, 2, 1},
		{4, 4, 3, 3, 1, 0},
		{4, 3, 2, 1, 1, 0},
		{4, 2, 3, 2, 1, 0},
		{4, 4, 3, 2, 1, 0},
		{3, 4, 3, 2, 0, 0},
		{5, 4, 4, 2, 3, 1},
		{5, 4, 2, 4, 1, 3}
	};

	solution(nVectInput);

}

void solution(std::vector<std::vector<int>>& nVectInput)
{
	// 2019-01-14 wssin
	// v[0][0]을 제외한 v[1][0] 부터 시작하여
	// v[N][1]부터 v[N][Length] 까지 정렬
	// std::sort는 퀵소트 기반
	for (int AxisY = 1; AxisY <= nVectInput[0][0]; AxisY++)
	{
		std::sort(nVectInput[AxisY].begin() + 1, nVectInput[AxisY].end(), std::greater<int>());
	}

	// 더미 코드
	int a = 10;

	// 정렬이 완료되었으니 이제 비교문 추가하면 됨.
}



// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
