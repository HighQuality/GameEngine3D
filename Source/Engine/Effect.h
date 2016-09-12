#pragma once

class VertexShader;
class PixelShader;
class InputLayout;

struct ID3D11InputLayout;

class Effect
{
public:
	Effect();
	~Effect();

	void AttachVertexShader(const char * aFileName, const char * aEntryPoint);
	void AttachPixelShader(const char * aFileName, const char * aEntryPoint);

	void Link(const InputLayout & aLayout);

	void Bind();

private:
	VertexShader *myVertexShader;
	PixelShader * myPixelShader;

	bool myIsLinked;
	ID3D11InputLayout * myLayout;
};
