#pragma once

#include "graphics/EruptPipeline.h"

#include "ECS/Entity.h"

namespace Erupt
{
	class SimpleRenderSystem
	{
	public:
		SimpleRenderSystem(EruptDevice& device, VkRenderPass renderPass);
		~SimpleRenderSystem();

		void RenderEntities(VkCommandBuffer commandBuffer, std::vector<Entity>& entities);

	private:
		void CreatePipelineLayout();
		void CreatePipeline(VkRenderPass renderPass);

	private:
		EruptDevice&					m_EruptDevice;

		std::unique_ptr<EruptPipeline>	m_EruptPipeline;
		VkPipelineLayout				m_PipelineLayout;
	};

} // namespace Erupt
