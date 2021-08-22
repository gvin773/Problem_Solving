#include <iostream>
#include <string>
using namespace std;
string str;
int main()
{
    getline(cin, str);
    if(str == "Marathon Edition 우승자") cout << "장려상\n레고 타워 브리지 - 10214\nsait2000\n";
    if(str == "Marathon Edition 준우승자 및 ReguIar Edition 준우승자") cout << "장려상\nKatamari Damacy REROLL\ncubelover\n";
    if(str == "ReguIar Edition 우승자 및 Speedrun Edition 우승자") cout << "장려상\n(도서) Speedrun Science: A Long Guide To Short Playthroughs\nxiaowuc1\n";
    if(str == "Speedrun Edition 준우승자") cout << "장려상\n치킨 기프티콘\nrubix\n";
    if(str == "이 대회에 참가하지 않은 사람 중 2019년 대회 최고 등수") cout << "결근상\n치킨 기프티콘\nhyeonguk\n";
    if(str == "모든 에디션에서 총점이 160억점에 가장 가까운 사람") cout << "대상\n16GB USB\n2u_my_light\n";
    if(str == "홀수와 짝수의 대결 문제의 오류를 발견한 사람") cout << "QA 상\n치킨 기프티콘\nnamnamseo\n";
    if(str == "4차 산업 혁명을 기계학습 없이 서브태스크 2까지만 푼 사람 중 추첨") cout << "UPWF 위원회 특별상\n(도서) 4차 산업혁명은 없다\npichulia\n";
    if(str == "배중률교를 정해가 아닌 방법으로 푼 사람 중 추첨") cout << "직관주의자상\n치킨 기프티콘\ndotorya\n";
    if(str == "Marathon Edition에서 Nonogram QR을 마지막으로 1점 이상 획득한 사람") cout << "QR 분해 상\n바코드 스캐너\n201812106\n";
    if(str == "연속합 2147483647 첫 0점자") cout << "Re: 제로부터 시작하는 다이나믹 프로그래밍 상\n빵\nzigui\n";
    if(str == "Beginning the Hunt 첫 만점자") cout << "\"Ghudegy Cup looks too intense for me\" 상\nRoller Coaster Tycoon 2: Triple Thrill Pack\nportableangel\n";
    else cout << "You Need a Minecraft 상\nMinecraft\ngreimul\n";
    return 0;
}
