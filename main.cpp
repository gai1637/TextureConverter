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
	kApplicacationPath,    //�A�v���P�[�V�����̃p�X
	kFilePath,             //�n���ꂽ�t�@�C���̃p�X

	NumArgument
};
int main(int argc, char* argv[]) {
	assert(argc >= NumArgument);

	//COM���C�u�����̏�����
	HRESULT hr = CoInitializeEx(nullptr, COINIT_MULTITHREADED);

	//�e�N�X�`���R���o�[�^
	TextureConverter converter;

	//�e�N�X�`���ϊ�
	converter.ConvertTextureWICToDDS(argv[kFilePath]);

	//COM���C�u�����̏I��
	CoUninitialize();

	system("pause");
	return 0;
}