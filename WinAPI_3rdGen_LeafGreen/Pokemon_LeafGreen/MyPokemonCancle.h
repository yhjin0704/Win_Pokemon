#pragma once
#include <EngineCore/Actor.h>

class AMyPokemonCancle : public AActor
{
public:
	// constrcuter destructer
	AMyPokemonCancle();
	~AMyPokemonCancle();

	// delete Function
	AMyPokemonCancle(const AMyPokemonCancle& _Other) = delete;
	AMyPokemonCancle(AMyPokemonCancle&& _Other) noexcept = delete;
	AMyPokemonCancle& operator=(const AMyPokemonCancle& _Other) = delete;
	AMyPokemonCancle& operator=(AMyPokemonCancle&& _Other) noexcept = delete;

	void SetCancleRenderer(std::string_view _Image);

protected:
	void BeginPlay() override;
	void Tick(float _DeltaTime) override;

private:
	UImageRenderer* ButtonRenderer = nullptr;
};

