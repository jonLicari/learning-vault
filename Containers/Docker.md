
## Layers

When instructions that modify the filesystem (`RUN`, `COPY`, `ADD`) are used, Docker creates a new read-only layer. Docker caches these layers; if you don't change a line in your Dockerfile, Docker reuses that layer from the cache to make your next build instantly fast. 

> [!Warning] 
> Layers are additive - if you download a 500MB SDK in layer 2, and delete it in layer 3, your final image _still includes_ that 500 MB download hidden in its history

## Stages

- Multi-stage builds let you use multiple `FROM` instructions in a single Dockerfile
- You can dedicate __Stage 1 (Build)__ to compiling your application which uses a heavy base image loaded with compilers, SDKs, and build tools
- You can then start __Stage 2 (Runtime)__ using a tiny lightweight base image. You selectively `COPY` only the compiled binary from Stage 1 into Stage 2
- When the build finishes, Stage 1 is completely thrown away. Your final image is incredibly lean, secure, and free of useless build bloat

## Stages vs Layers

| Feature       | Layers                                                  | Stages                                                        |
| ------------- | ------------------------------------------------------- | ------------------------------------------------------------- |
| Represents    | Immutable snapshot of file system changes               | Distinct build phase with its own base image                  |
| How to Create | Commands like `RUN`, `COPY`, `ADD`                      | Using `FROM` statement in Dockerfile                          |
| Primary Goal  | Enables step-by-step caching and reusability            | Separates build tools from runtime to shrink image sizes      |
| Persistence   | Every layer in the final stage stays in the final image | Throwaway stages are discarded; only the final stage is saved |

Example:

```Dockerfile
# ---------------------------------------------------------
# STAGE 1: The Builder Stage
# ---------------------------------------------------------
FROM golang:1.21 AS builder        # <- Starts Stage 1
WORKDIR /app                       # <- Layer 1
COPY . .                           # <- Layer 2
RUN go build -o myapp              # <- Layer 3 (Creates the executable)

# ---------------------------------------------------------
# STAGE 2: The Final Runtime Stage
# ---------------------------------------------------------
FROM alpine:latest                 # <- Starts Stage 2 (Discards Stage 1 layers!)
WORKDIR /root/                     # <- Layer 4
COPY --from=builder /app/myapp .   # <- Layer 5 (Only grabs the tiny executable)
CMD ["./myapp"]
```

The result is that the final production image only contains the layers from the Stage 2 (Alpine + your application binary). The bulky Go compiler layers from Stage 1 never leave your development machine.