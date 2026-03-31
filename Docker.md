
## **Key Docker Concepts

1. **Image**
    - A blueprint for a container.
    - Think of it like a **pre-packaged OS + software**.
    - Example: `ubuntu:22.04` is an Ubuntu Linux image.
        
2. **Container**
    - A running instance of an image.
    - Think of it as a **virtual workspace**: isolated, with its own filesystem.
    - Any changes you make inside the container can be **lost** when it stops — unless you save them or use volumes.
        
3. **Volume / bind mount**
    - Lets the container see **specific files or folders** from your Mac.
    - Example: your portfolio repo.
    - Only the folder you mount is visible; the rest of your filesystem is hidden.
        
4. **Commit / save**
    - You can **save a container’s state as a new image** if you want to preserve installed software or changes.
    - Often for dev, it’s easier to **mount your repo** and re-run the container instead of committing.

---

## **Key takeaways**

- Container = isolated workspace    
- Mount only your repo → Cursor cannot access other folders
- Stop/start container → keeps workspace ready
- Optional: `docker commit` to save software + configs
- Sharing: easiest via Docker Hub or just the repo + recreate container

### Isolated Environment

- Any software installed inside the container does not exist outside of it and therefore does not touch your local machine's filesystem
- `docker commit` creates a **new Docker image** from the container’s current state (local only). You can save it to the cloud by using `docker push` which pushes it to the docker hub
- You don't need to specify the volume to mount every time you start the container, but if you remove the container and spin a new one, then yes you will need to specify the volume
- Because `/workspace` is a mount of your local repo, commits affect the **same repo on your Mac**. You don’t need to make commits outside the container; it’s just like working locally.  
	-  Caveat: Git credentials:
		- You may need to configure Git with your name/email and authentication (SSH keys or personal access token) **inside the container** to push to GitHub.
		- For security, you can mount your SSH folder or configure a token inside the container.