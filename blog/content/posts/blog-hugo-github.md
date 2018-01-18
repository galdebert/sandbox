---
title: "Write a Blog with Hugo and host it on Github"
date: 2018-01-18T16:56:13+01:00
draft: true
---

I wanted to start a blog about programming, writing markdown. I tried Hugo, one of the many static pages generators that works very well with github pages. I wanted to try Hugo before any other because it's written in Go. Even if I have no real life experience with Go, I really like what I read about the simplicity of the Go ecosystem. Hopefully, Hugo exhibits the same qualities. Let's see.

# Create your github pages repository

- create a repo named "_username_/github.io", where _username_ is your username
- don't clone it locally for now

Follow https://pages.github.com/ for more details.

# Hugo interesting features

From http://gohugo.io/about/features/, the features that catched my attention were:

- Completely cross platform, with easy installation on macOS, Linux, Windows, and more
- Hugo sites can be hosted anywhere, including ..., GitHub Pages, ...
- Renders changes on the fly with LiveReload as you develop
- Powerful theming
- Integrated Disqus comment support
- Integrated Google Analytics support
- Syntax highlighting powered by Pygments

# Install Hugo

The install page http://gohugo.io/getting-started/installing/ has everything you need. Here is a quick 2 steps installs summary:

## 1. (on windows) Install chocolatey - yes, do it, it's worth it
I'm mostly on windows these days, and installing hugo was the occasion to install chocolatey, the package manager for Windows.

You should read: https://chocolatey.org/install, one option that worked for me was to run the following command from a powershell (ran as administrator):
```
Set-ExecutionPolicy Bypass -Scope Process -Force; iex ((New-Object System.Net.WebClient).DownloadString('https://chocolatey.org/install.ps1'))
```

## 2. Install hugo with chocolatey
```
choco install hugo -confirm
```

## 3. Install Pygments (Optional) 

The Hugo source code highlighting uses the Pygments python package:
```
pip install Pygments
```

# Quick start

http://gohugo.io/getting-started/quick-start/

## 1. Create the basic directory structure

There is something unclear here, should I:
- put the source files (markdown, config, images) in the "_username_/github.io" repository
- put the source files (markdown, config, images) in anothre repository: "blog-src" for ex, and have "_username_/github.io" contain only the generated pages 

let's read:
http://gohugo.io/hosting-and-deployment/hosting-on-github/

https://help.github.com/articles/configuring-a-publishing-source-for-github-pages/
says: not everyone prefers the output site live concomitantly with source files in version control.

what is the best practice

```
hugo new site C:\Dev\galdebert.github.io-src
```

## 2. Download and use a theme
```
cd C:\Dev\galdebert.github.io-src
git init
git submodule add https://github.com/budparr/gohugo-theme-ananke.git themes/ananke
```
and add the following line to `config.toml`
```
theme = "ananke"
```

## 3. Add some content

```
hugo new posts/my-first-post.md
```

This creates the file:<br>
`C:\Dev\galdebert.github.io-src\content\posts\my-first-post.md`

You can also create the file manually, but<br>
`hugo new`<br>
adds a few lines at the start of the md file:
```
---
title: "Write a Blog with Hugo and Github"
date: 2018-01-18T16:56:13+01:00
draft: true
---
```

Write stuff in the md file.

## 4. Generate the html and serve it locally

```
hugo server -D
```
-D means: include content marked as draft

View the locally generated html in your browser at `http://localhost:1313/`

Now the html is automatically generated everytime the content is changed. So you can see your changes in realtime.
It works like a charm with the vs-code and the setting `"files.autoSave": "afterDelay"`

# aa
