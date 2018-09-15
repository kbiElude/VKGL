VKGL
====

OpenGL 3.2 Core Profile implementation over Vulkan.


This project is in WIP state:
* It is *not* usable in its current form.
* VKGL builds and correctly intercepts all relevant API calls required to run GL apps, assuming
  the tested application is run using the included Launcher project.
* The development is planned to progress at a slow (but steady) pace due to time constraints.


Contributions: (last updated: 09/15/18)
* Not welcome *yet*
* This status is expected to change once all the scaffold code for the Vulkan backend is ready.


Linux support:
* Not planned at this stage (though any OS-specific tools are going to be abstracted away to
  pave way for contributions in the future)


Current project goals: (last updated: 09/15/18)
* Being able to correctly run all example applications coming from the LearnOpenGL project
  (https://github.com/JoeyDeVries/LearnOpenGL). The caveat here is that they all seem
  to create GL 3.3 contexts, even if GL 3.2 would do just fine. This can be easily
  adjusted by manually modifying their code.
* Being able to launch & enjoy ID Software's Doom 3 game in the wrapped environment.
* Khronos CTS conformance
* Support for newer core GL versions.
