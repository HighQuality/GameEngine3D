#pragma once

class GenericMesh;
class Effect;

class Model
{
public:
	Model(std::shared_ptr<Effect> aEffect);
	Model(std::shared_ptr<Effect> aEffect, std::shared_ptr<GenericMesh> aMesh);
	virtual ~Model();
	
	void Render(const Matrix44f & aMatrix) const;
	void InstantRender(const Matrix44f & aWorldMatrix) const;

	const std::vector<std::shared_ptr<GenericMesh>> & GetMeshes() const;
	
	const BoundingBoxf & GetBoundingBox() const;

	void SetEffect(const std::shared_ptr<Effect> & aEffect);

protected:
	void AddMesh(std::shared_ptr<GenericMesh> aMesh);

private:
	std::vector<std::shared_ptr<GenericMesh>> myMeshes;
	std::shared_ptr<Effect> myEffect;
	BoundingBoxf myBoundingBox;
};
