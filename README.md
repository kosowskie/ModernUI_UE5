# ModernUI_UE5

My example of modern approach to UI in Unreal Engine 5 using C++, UMG, Common UI, Enhanced Input and MVVM.

# Common UI

It's easily handle navigation and focus on certain displayed UI. My project is gamepad oriented first so CommonUI let us smoothly take care of all difficulties with gamepad.
CommonUI is one of the most powerful tool in Unreal and before give it a shoot i recommend to take a look at documentation: <br />
https://dev.epicgames.com/documentation/en-us/unreal-engine/common-ui-quickstart-guide-for-unreal-engine

# Enhanced Input

This is still experiental plugin in UE5.5, but It's worth paying attention to. And I mean not gameplay focus EI, but the Enhanced Input compatible with CommonUI.
I managed to configure all setups with Unreal Engine documentation about this plugin: <br />
https://dev.epicgames.com/documentation/en-us/unreal-engine/using-commonui-with-enhnaced-input-in-unreal-engine

# MVVM with UMG bindings

Architectural pattern commonly used in software development. Unfortunately, Unreal Engine has not officially supported the MVVM pattern so far, which would also directly enable a binding system, such as the one available in .NET MUAI.
This plugin provides ready-made implementations of MVVM pattern classes, but also provides integration with UMG through data binding of individual components in Widget Blueprint. 
The plugin is also still experimental and it is easy to encounter errors when creating Viewmodels in WBP, but the documentation itself is well and thoroughly described: <br />
https://dev.epicgames.com/documentation/en-us/unreal-engine/umg-viewmodel-for-unreal-engine
