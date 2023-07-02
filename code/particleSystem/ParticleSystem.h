#pragma once

#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <iostream>
#include <random>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "particle/Particle.h"

namespace ParticleSystemEditor
{
	class ParticleSystem 
	{
	public:
		std::vector<Particle*>* particles;

		ParticleSettings* GetParticleSettingsPtr();

		ParticleSystem();
		~ParticleSystem();

		void Update();
		void Render();

	private:
		ParticleSettings* settings;
		float restEmission;

		void Emit();
	};
}