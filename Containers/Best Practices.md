
Use multi-stage builds 

- reduces the final image size by creating cleaner separation between the building of the image and the final output
- Split Dockerfile into distinct stages to make sure that the resulting output only contains the files that are needed to perform that specific function (i.e. running an application)

Create Reusable stages
- Create stages that amalgamate common functionality to reduce or eliminate repeated operations between stages
- Docker will only need to build the common stage once, saving memory in later stages by not having to rebuild everything over again

Use `--no-cache` for clean builds
- this flag disables the cache forcing Docker to rebuild all layers from scratch: `docker build --no-cache -t my-image:my-tag .`

Exclude with .dockerignore
- File exclusion pattern is the same as a .gitignore file

Each RUN creates a layer
- Always try to combine commands that delete files in the same command that adds them
	- If you delete a file that was created in a different layer, all the union filesystem does is register the filesystem change in a new layer, the file still exists in the previous layer and is shipped over the network and stored on disk. 
	- If you download source code, extract it, compile it into a binary, then delete the `.tgz` and source files at the end, you really want this all done in a single layer to reduce image size
- Order operation layers based on frequency of update; ideally the most common dependencies are ones not being updated as frequently (e.g. base image, git, compiler) so less layers are needed to be rebuilt every time 