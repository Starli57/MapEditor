#include "Inspector.h"

namespace ParticleSystemEditor
{
    Inspector::Inspector(ParticleSettings* settings)
    {
        _settings = settings;
    }

	void Inspector::Render()
	{
        ImGui::Begin("Inspector");

        if (ImGui::CollapsingHeader("Spawn"))
        {
            ImGui::DragInt("Spawn Rate", &_settings->particlesPerEmission, 1, 0, 600);
            ImGui::DragFloat("Spawn Period", &_settings->emissionPeriod, 0.01f, 0, 60);

            ImGui::Spacing();
            ImGui::DragFloat3("Position", glm::value_ptr(_settings->emissionPosition), 0.1f);
            ImGui::DragFloat3("Radius", glm::value_ptr(_settings->emissionRadius), 0.01f, 0, ImGuiSliderFlags_AlwaysClamp);

            ImGui::Spacing();
            ImGui::DragFloatRange2("Lifetime", &_settings->minLifetime, &_settings->maxLifetime, 0.01f, 0.0f, 120, "Min: %.2f", "Max: %.2f", ImGuiSliderFlags_AlwaysClamp);
        }
        
        if (ImGui::CollapsingHeader("Movement", ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::SeparatorText("Move Direction");
            ImGui::DragFloat3("Direction", glm::value_ptr(_settings->direction), 0.001f, -1, 1);
            ImGui::DragFloat3("Direction Noise", glm::value_ptr(_settings->directionNoise), 0.001f);

            ImGui::SeparatorText("Move Velocity");
            ImGui::DragFloatRange2("Velocity", &_settings->minVelocity, &_settings->maxVelocity, 0.01f, 0.0f, 120, "Min: %.2f", "Max: %.2f", ImGuiSliderFlags_AlwaysClamp);
            ImGui::DragFloat("Velocity Damping", &_settings->velocityDamping, 0.00001f, 0, 1, "%.5f");

            ImGui::SeparatorText("Rotation");
            ImGui::DragFloat3("Axis", glm::value_ptr(_settings->rotationVector), 0.01f, -1, 1);
            ImGui::DragFloatRange2("Rotation Speed", &_settings->minRotation, &_settings->maxRotation, 0.01f, -FLT_MAX, FLT_MAX, "Min: %.2f", "Max: %.2f");
        }

        if (ImGui::CollapsingHeader("Particle Visual", ImGuiTreeNodeFlags_DefaultOpen))
        {
            ImGui::SeparatorText("Scale");
            ImGui::DragFloat3("Start Scale", glm::value_ptr(_settings->startScale), 0.01f);
            ImGui::DragFloat3("End Scale", glm::value_ptr(_settings->endScale), 0.01f);

            ImGui::SeparatorText("Color");
            ImGui::ColorEdit4("Start Color", glm::value_ptr(_settings->startColor));
            ImGui::ColorEdit4("End Color", glm::value_ptr(_settings->endColor));

        }


        ImGui::End();
	}
}