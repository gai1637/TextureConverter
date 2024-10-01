#include<cstdio>
#include<cstdlib>
#include<d3d12.h>
#include<dxgi1_6.h>
#include<cassert>
#include"TextureConverter.h"


#pragma comment(lib, "d3d12.lib")
#pragma comment(lib, "dxgi.lib")
enum Argument
{
	kApplicacationPath,    //アプリケーションのパス
	kFilePath,             //渡されたファイルのパス

	NumArgument
};
int main(int argc, char* argv[]) {
	assert(argc >= NumArgument);

	//COMライブラリの初期化
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	//テクスチャコンバータ
	TextureConverter converter;

	//テクスチャ変換
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COMライブラリの終了
	CoUninitialize();

	system("pause");
	return 0;
}