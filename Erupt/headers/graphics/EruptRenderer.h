#pragma once

#include "graphics/EruptWindow.h"
#include "graphics/EruptPipeline.h"
#include "graphics/EruptSwapChain.h"

#include "ECS/Entity.h"

#include "core/Log.h"

#include <memory>
#include <vector>

namespace Erupt
{
	static constexpr int WINDOW_WIDTH = 800;
	static constexpr int WINDOW_HEIGHT = 600;

	class EruptRenderer
	{
	public:
		EruptRenderer() = default;
		~EruptRenderer();

		EruptRenderer(const EruptRenderer&) = delete;
		EruptRenderer& operator=(const EruptRenderer&) = delete;

		void Init();
		void DrawFrame();

		Window& GetWindow() { return m_EruptWindow; }
		EruptDevice& GetDevice() { return m_EruptDevice; }

	private:
		void CreatePipelineLayout();
		void CreatePipeline();
		void CreateCommandBuffers();
		void FreeCommandBuffers();

		void RecreateSwapchain();
		void RecordCommandBuffer(int imageIndex);

		void LoadEntities();
		void RenderEntities(VkCommandBuffer commandBuffer);

	private:
		Window							m_EruptWindow{ WINDOW_WIDTH, WINDOW_HEIGHT, "Henlo Vulkan!" };
		EruptDevice						m_EruptDevice{ m_EruptWindow };
		std::unique_ptr<EruptSwapChain>	m_EruptSwapChain;

		std::unique_ptr<EruptPipeline>	m_EruptPipeline;
		VkPipelineLayout				m_PipelineLayout;

		std::vector<VkCommandBuffer>	m_CommandBuffers;

		std::vector<Entity>				m_Entities;
	};

}