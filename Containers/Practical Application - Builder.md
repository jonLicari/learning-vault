
For a workflow where you want to build a multi-repo, you may want to achieve a workflow where a Docker environment has been created for portability and within it, various scripts perform operations such as cloning, dependency installation, application building, and exporting of computed binaries.

An example of an optimized workflow makes use of Docker multi-stage image 