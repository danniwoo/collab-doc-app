# COMP2017 Assignment 2: Collaborative Markdown Editor

## 📝 Overview

This project implements a simplified collaborative Markdown editor using a client-server architecture in C. It supports multiple clients editing a shared document in real time via named pipes (FIFOs) and POSIX threads. The document supports Markdown formatting and enforces role-based access control.

---

## 🧠 Key Features

- Multi-client support with one POSIX thread per client
- Real-time editing with version control and synchronization
- Named pipes (FIFOs) for bi-directional interprocess communication
- Markdown formatting: headings, bold, italics, lists, links, etc.
- Role-based access control via `roles.txt` (read/write permissions)
- Signal-based handshake for client-server connection (`SIGRTMIN`)

---

## 📂 File Structure

| File              | Description                              |
|-------------------|------------------------------------------|
| `server.c`        | Main server logic, client management     |
| `client.c`        | Terminal-based editor, command sender    |
| `markdown.c/h`    | Core logic for editing and formatting    |
| `document.h`      | Document structure definitions           |
| `roles.txt`       | List of users and their permissions      |
| `Makefile`        | Build automation                         |

---

## 🛠️ Build Instructions

```bash
make