#include <stdio.h>

int main(int argc, char* argv[]) 
{
	/* コマンドライン引数が2個の場合、（プログラム名を含めてargcは3個）
	 * そもそも問題文がおかしいような。。
	 */
	if (argc - 3) {
		puts("not two!");
	}
	else {
		puts("two!");
	}

}