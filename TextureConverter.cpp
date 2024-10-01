#include "TextureConverter.h"
#include<Windows.h>

void TextureConverter::ConvertTextureWICToDDS(const std::string& filepath)
{
	//�e�N�X�`���t�@�C����ǂݍ���
	LoadWICTextureFromFile(filepath);


}

void TextureConverter::LoadWICTextureFromFile(const std::string& filePath)
{
	//�t�@�C�������C�h������ɕϊ�����
	std::wstring wfilePath = ConvertMultiByteStringToWideString(filePath);
	//WIC�e�N�X�`���̃��[�h
	HRESULT result = LoadFromWICFile(wfilePath.c_str(), DirectX::WIC_FLAGS_NONE, &metadata_, scratchImage_);
	assert(SUCCEEDED(result));
}

std::wstring TextureConverter::ConvertMultiByteStringToWideString(const std::string& mString)
{
	//���C�h������ɕϊ������ۂ̕��������v�Z
	int filePathBufferSize = MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, nullptr, 0);

	//���C�h������
	std::wstring wString;
	wString.resize(filePathBufferSize);

	//���C�h������ɕϊ�
	MultiByteToWideChar(CP_ACP, 0, mString.c_str(), -1, &wString[0], filePathBufferSize);

	return wString;
}
