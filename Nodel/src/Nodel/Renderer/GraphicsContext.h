#pragma once
namespace Nodel {
    class GraphicsContext {
    public:
		virtual ~GraphicsContext() = default;

		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;

        static Uni<GraphicsContext> Create(void* window);
    };
}
 
