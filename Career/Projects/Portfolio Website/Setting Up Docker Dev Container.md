
## **2️⃣ Example setup: isolated workspace for your portfolio repo**

Assume:

- Repo path on Mac:    
    `/Users/jonathan/Projects/portfolio`
- You want a safe environment to run Cursor in.    

---

### **Step A — Choose an image**

For simplicity, use Ubuntu:

`docker pull ubuntu:22.04`

- Downloads a fresh Ubuntu Linux image from Docker Hub.
- Can also include other tools in a custom image later (e.g., Python, Node.js, Cursor).

---

### **Step B — Run a container with your repo mounted**

`docker run -it \   -v /Users/jonathan/Projects/portfolio:/workspace \   --name cursor-workspace \   ubuntu:22.04`

**Explanation:**

- `-it` → interactive terminal
- `-v /Users/jonathan/Projects/portfolio:/workspace` → mount your repo
- `--name cursor-workspace` → gives the container a friendly name
- `ubuntu:22.04` → image to use
- `/workspace` → inside the container, that’s where your repo lives

Inside the container:

`cd /workspace ls`

- You’ll see all your repo files.
- The container **cannot see anything outside `/workspace`**.

---

### **Step C — Installing dependencies inside container**

If Cursor or other tools need Python, Node, etc.:

`apt update apt install -y python3 python3-pip git`

> These changes exist **only in this container** (unless you save it as a new image).

---

## **3️⃣ Stopping & restarting the container**

- Stop container: `docker stop cursor-workspace`

- List containers: `docker ps -a`

- Restart: `docker start -ai cursor-workspace`
	- `-a` attaches terminal; `-i` interactive

> Your mounted repo is unchanged because it lives on your Mac.

---

## **4️⃣ Saving the container state (optional)**

If you want a reusable setup with installed dependencies:

`docker commit cursor-workspace jonathan/cursor-image:latest`

- Creates a **new image** `jonathan/cursor-image:latest`
- Next time, you can run: `docker run -it -v /Users/jonathan/Projects/portfolio:/workspace jonathan/cursor-image:latest`
- Saves the installed software, configs, etc.

---

## **5️⃣ Sharing the container across devices**

Options:

1. **Share the image** via Docker Hub:
    

`docker login docker tag jonathan/cursor-image:latest <dockerhub-username>/cursor-image:latest docker push <dockerhub-username>/cursor-image:latest`

- On another device:
    

`docker pull <dockerhub-username>/cursor-image:latest docker run -it -v /path/to/repo:/workspace <dockerhub-username>/cursor-image:latest`

2. **Share the repo only** + recreate container from standard image:
- Often easier — just clone the repo and run `ubuntu:22.04` or your custom image.
- No need to transfer the entire container.

