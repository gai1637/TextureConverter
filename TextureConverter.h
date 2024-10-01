#pragma once
#include<string>
class TextureConverter
{
public:
	///<summary>
	///テクスチャをWIからDDSに変換する
	///</summery>
	///<param name="filePath">ファイルパス</param>
	void ConvertTextureWICToDDS(const std::string& filepath);
private:
	///<summary>
	///テクスチャファイル読み込み
	///</summery>
	///<param name="filePath">ファイルパス</param>
	void LoadWICTextureFromFile(const std::string& filePath);
	///<summary>
	///マルチバイト文字列をワイド文字列に変換
	///</summery>
	///<param name="filePath">マルチバイト文字列</param>
	static std::wstring ConvertMultiByteStringToWideString(const std::string& mString);
};

