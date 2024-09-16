1. Reading the UML Diagram

    Understand the Diagram:
        Review the UML diagram carefully. Identify the key components such as classes, relationships, and interactions.
        Pay attention to class diagrams, sequence diagrams, and activity diagrams if provided.

2. Extract Requirements:
        Note down the classes and their responsibilities.
        Identify the tasks, queues, and synchronization mechanisms required based on the UML.

3. Setting Up the Development Environment

    Setup ESP32:
        Follow the ESP-IDF setup guide to configure your development environment.

3. Implementing the System

    Create a New Project:
        Use ESP-IDF to create a new project:

        bash

        idf.py create-project <project_name>

    Implement Classes:
        Create .cpp files for each class defined in the UML diagram.
        Implement the class methods and attributes according to the UML specifications.
        Ensure that classes are properly encapsulated and follow object-oriented principles.

    FreeRTOS Tasks and Synchronization:
        Implement FreeRTOS tasks as specified in the UML diagram.

    Coding Standards:
        Follow the coding standards provided:
            Comments for every function and class.
        Ensure code is clean, readable, and well-documented.

4. Testing

    Unit Testing:
        Write unit tests for your classes and tasks. Use the ESP-IDF testing framework if applicable.

    Integration Testing:
      Test Description: LED Alternation

    In this test, you will work with 3 LEDs that need to alternate in a sequence with three distinct timings. Follow these requirements:

        Initial Setup:
            LED Sequence: The LEDs should start in a specific sequence, turning on one by one.
            Spacing: Ensure that each LED is positioned separately from the others at least 500ms.

        Behavior:
            Single LED On: At any given moment, only one LED should be illuminated.
            Timing Intervals: The LEDs should alternate based on three different timing intervals.

    The test will verify that your system correctly implements the sequence and timing control for the LEDs.

5. Using Git for Version Control


Commit Your Changes:

    Add files to the staging area and commit:

    git branch feature/TaskExcersie

    Select some file to ignore with gitignore file, you can ask me how to this.

    git add .
    git commit -m "Initial commit with UML-based implementation"


6. Submission

    Verify Implementation:
        Ensure your code adheres to the provided coding standards.
        Verify that the system operates correctly on the ESP32.

    Upload to Git:
        Make sure all your code is committed and pushed to the Git repository.

    Submit:
        Send me a code review.