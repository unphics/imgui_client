#ifndef client_example_example
#define client_example_example

#include "imgui.h"

namespace client::example {

// imgui官方示例
void example(bool* b_show_demo_wnd, bool* b_show_another_wnd, ImVec4* clear_color, ImGuiIO& io) {
    // 1. Show the big demo window (Most of the sample code is in ImGui::ShowDemoWindow()! You can browse its code to learn more about Dear ImGui!).
    if (*b_show_demo_wnd) {
        ImGui::ShowDemoWindow(b_show_demo_wnd);
    }
    // 2. Show a simple window that we create ourselves. We use a Begin/End pair to create a named window.
    {
        static float f = 0.0f;
        static int counter = 0;

        ImGui::Begin("Hello, world!");                          // Create a window called "Hello, world!" and append into it.

        ImGui::Text("This is some useful text.");               // Display some text (you can use a format strings too)
        ImGui::Checkbox("Demo Window", b_show_demo_wnd);      // Edit bools storing our window open/close state
        ImGui::Checkbox("Another Window", b_show_another_wnd);

        ImGui::SliderFloat("float", &f, 0.0f, 1.0f);            // Edit 1 float using a slider from 0.0f to 1.0f
        ImGui::ColorEdit3("clear color", (float*)&clear_color); // Edit 3 floats representing a color

        if (ImGui::Button("Button"))                            // Buttons return true when clicked (most widgets return true when edited/activated)
            counter++;
        ImGui::SameLine();
        ImGui::Text("counter = %d", counter);

        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / io.Framerate, io.Framerate);
        ImGui::End();
    }
    // 3. Show another simple window.
    if (*b_show_another_wnd) {
        ImGui::Begin("Another Window", b_show_another_wnd);   // Pass a pointer to our bool variable (the window will have a closing button that will clear the bool when clicked)
        ImGui::Text("Hello from another window!");
        if (ImGui::Button("Close Me")) {
            *b_show_another_wnd = false;
        }
        ImGui::End();
    }
}

// 视频教程的示例
void teach() {
    static bool b_collapse; // 注意: 临时写法
    ImGui::Begin(u8"WndName: 菜单", &b_collapse);
    
    ImGui::Text("hello world");
    ImGui::TextColored(ImColor(255, 0.0, 0.0), "TextColored"); // ImColor取值是0~255
    ImGui::SameLine(); // SameLine会让上一个TextColored和下面的BulletText保持同一行
    ImGui::BulletText("BulletText");

    static bool b_clicked = false;
    bool clicked = ImGui::Button("Button", ImVec2(80, 40)); // 点击会返回1,否则返回0
    if (clicked) {
        b_clicked = true;
    }
    if (b_clicked) {
        static bool b_show_tips_wnd = false;
        ImGui::Begin(u8"点击了", &b_show_tips_wnd);
        ImGui::End();
    }

    bool radio_clicked;
    ImGui::RadioButton("RadioButton", &radio_clicked);

    static int idx_select;
    ImGui::RadioButton("RadioButton Combine 0", &idx_select, 0);
    ImGui::RadioButton("RadioButton Combine 1", &idx_select, 1);
    ImGui::RadioButton("RadioButton Combine 2", &idx_select, 2);

    bool check = false;
    ImGui::Checkbox(u8"复选框", &check); // 注意:这是个传出参数

    static float drag_val = 0.0f;
    ImGui::DragFloat(u8"滑块条", &drag_val, 0.1f, 0, 10);

    static float slider_val = 0.0f;
    ImGui::SliderFloat(u8"滑动条", &slider_val, 0, 10);

    static char input[1024];
    ImGui::InputText(u8"输入框", input, sizeof(input));

    {
        // 这些都会画在绘制窗口上，如果没有隐藏了绘制窗口则会画在以显示器左上角为原点的位置
        ImGui::GetForegroundDrawList()->AddLine(ImVec2(0,0), ImVec2(1000, 1000), ImColor(0, 255, 0), 2.0f);
        ImGui::GetForegroundDrawList()->AddRect(ImVec2(0,0), ImVec2(1000, 1000), ImColor(0, 255, 0), /*圆角*/10, 0, 2.0f);
        ImGui::GetForegroundDrawList()->AddCircle(ImVec2(100, 100), 100, ImColor(0, 255, 0), /*细分*/0, 3.0f);
        ImGui::GetForegroundDrawList()->AddText(ImVec2(100, 100), ImColor(0, 255, 255), u8"ImGui::GetForegroundDrawList()->AddText()");
    }

    ImGui::End();
}

}

#endif