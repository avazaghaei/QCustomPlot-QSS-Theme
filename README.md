# QCustomPlot with Dynamic QSS Themes

This Qt C++ application extends the QCustomPlot library to not only provide interactive data visualizations but also to demonstrate dynamic, runtime QSS theme switching. The primary focus of this project is to quickly change the visual appearance of the application using QSS while maintaining the robust plotting functionality provided by QCustomPlot.

## Overview

This project builds on our previous work with QCustomPlot applications by introducing a dynamic QSS theme system. In addition to familiar features such as point selection, plotting, axis customization, zoom, and area selection, the application allows users to switch between multiple predefined themes at runtime, providing an instant visual transformation.

While many of the underlying data visualization features remain similar to our other QCustomPlot-based projects, this repository highlights:
- Dynamic Theme Switching: Quickly apply different QSS themes during runtime.
- Enhanced User Interface: A clean, code-based GUI that prioritizes flexibility and maintainability.

## Features

### Dynamic QSS Theme Switching
- Runtime Theme Change: Switch themes on the fly without restarting the application.
- Multiple Predefined Themes: Quickly compare and select the best visual appearance for your data visualizations.
- Live Preview: Immediate visual feedback as themes are applied.

### QCustomPlot Enhancements
- Interactive Data Visualization:
  - Customize plot types, axes, zoom, and pan capabilities.
  - Precise point selection for detailed data analysis.
- Custom Modifications:
  - Tailored modifications to QCustomPlot for improved performance and unique visualization requirements.

### Code-Based GUI Development
- Clean & Maintainable Code:
  - The entire GUI is developed programmatically, fostering reusability and version control friendliness.
- Flexibility:
  - Easily adapt or extend the UI without being tied down by drag-and-drop generated code.

## Getting Started

### Prerequisites
- **Qt Framework:** Ensure you have Qt 5 or Qt 6 installed.
- **QCustomPlot Library:** This project uses a custom build of QCustomPlot for specialized visualizations.
- **Development Environment:** Use Qt Creator or any preferred IDE that supports Qt project development.

### Building the Application
1. Clone the Repository:
   git clone https://github.com/avazaghaei/QCustomPlot-QSS-Theme.git
2. Open the Project:

    Open the provided .pro file in Qt Creator.

3. Build the Project:

    Click the Build button in Qt Creator.

4. Run the Application:

    Execute the application from within Qt Creator to see the interactive plotting and live theme switching in action.
	
### Building the ApplicationUsage

    Theme Switching:
    At runtime, change the application's theme through the provided UI controls. This will immediately update the look of all widgets, including the QCustomPlot visualization.

    Data Visualization:
    Interact with the plot using built-in features like zooming, panning, and point selection.

### Building the ApplicationFuture Enhancements

    Extended Theme Library: Expand the set of available themes to offer more design options.

    User-Defined Themes: Allow users to create and apply their own custom QSS themes.

    Enhanced Interactivity: Improve plot interaction features further while maintaining dynamic theme flexibility.

### Building the ApplicationContribution

	Contributions and feedback are welcome! Please fork the repository and submit pull requests or open issues for any enhancements or bugs you find.

### Building the ApplicationLicense

	This project is licensed under the MIT License. See the LICENSE file for details.