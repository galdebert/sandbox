
# How to avoid always entering git credentials

https://git-scm.com/docs/gitcredentials

On Linux, let's use `git config --global credential.helper cache`

It's the only solution that works cross clients on Linux

app       |core.askpass|github token|credential.helper cache|
----------|------------|------------|-----------------------|
cmdline   |    yes     |    no      | yes, but not windows  |
vscode    |    no      |    no      | yes, but not windows  |
smartgit  |    no      |    yes     | yes, but not windows  |

On windows, `git config --global credential.helper manager` is a very good option.
Except when github is very slow to authenticate, then it's mess:
- tons of authentication popups
- tons of github personal token created


# To avoid typing the username

```
[credential "https://example.com"]
    username = galdebert
```


# store passwords in plain **plain text**, very bad !

```
git config --global credential.helper store
```

# store passwords in memory for some time

`credential.helper cache` does not work on windows !!
```
git config --global credential.helper cache
```


# Store passwords using an external password manager

## Windows
```
git config --global credential.helper manager
```


## OSX
```
git config --global credential.helper osxkeychain
or
git config --global credential.helper libsecret
```

# askpass on kubuntu

Not using a credential manager but the askpass mechanism instead
```
git config --global --unset credential.helper
git config --global core.askpass /usr/bin/ksshaskpass
git config --global credential.username galdebert
```

Note: `gnome-keyring` and `libsecret` linux "credential managers" did not work for me.


# WHEN YOU HAVE DIFFERENT USERS FOR DIFFERENT REPOS

You can configure a repo to use a specific
- user.name
- user.email
- credential.username
which overrides the global configuration

**From the root of the repo**, run:

```
git config user.name "Your Name Here"
git config user.email your@email.com
git config credential.username your_github_username
```

to verify what user a given repo uses:
```
git config --get user.email
```

## With the Git-Credential-Manager-for-Windows

Make Git-Credential-Manager-for-Windows use credentials per repo
```
git config --global credential.httpusepath true
```

other Git-Credential-Manager-for-Windows configuration:

https://github.com/Microsoft/Git-Credential-Manager-for-Windows/blob/master/Docs/Configuration.md

https://github.com/Microsoft/Git-Credential-Manager-for-Windows#notice-experiencing-github-pushfetch-problems



# SSH

http://guides.beanstalkapp.com/version-control/git-on-windows.html#installing-ssh-keys

https://help.github.com/articles/generating-a-new-ssh-key-and-adding-it-to-the-ssh-agent/


## 1. Generate an SSH key for that computer

We'll need to run ssh-keygen. It looks like we can use either:
- the git-bash version
- the windows version

```
λ where ssh-keygen
C:\Windows\System32\OpenSSH\ssh-keygen.exe
C:\dev\git\usr\bin\ssh-keygen.exe

λ where ssh-agent
C:\Windows\System32\OpenSSH\ssh-agent.exe
C:\dev\git\usr\bin\ssh-agent.exe
```

let's run git-bash: `C:\dev\git\git-bash`

and run:
```
ssh-keygen -t rsa -b 4096 -C "your_email@example.com"
```
- `-t rsa` is the encoding
- `-b 4096` is the number of bits
- `-C "your_email@example.com"` is a comment
This creates a new ssh key, using the provided email as a label.


- this asks for location, default is `C:\Users\galde\.ssh`, it's fine, press enter
- this asks for a pass phrase, no need for one, press enter. is set, the pass phrase will be asked every time the ssh key is used.
  - the advantage that the passphrase gives you is that if someone is able to read your private key, they are 'unable' to use it.
  - make sure to generate a private-key/public-key for each { user, machine }

Now the key is generated

in `C:\Users\galde\.ssh`:
- `id_rsa` contains the private key, **this has to remain secret all the time**
- `id_rsa.pub` contains the public key, that you can put on the internet, for ex:
ssh-rsa AAAAB3NzaC1yc2EAAAABIwAAAQEAyyA8wePstPC69PeuHFtOwyTecByonsHFAjHbVnZ+h0dpomvLZxUtbknNj3+
c7MPYKqKBOx9gUKV/diR/mIDqsb405MlrI1kmNR9zbFGYAAwIH/Gxt0Lv5ffwaqsz7cECHBbMojQGEz3IH3twEvDfF6cu5p
00QfP0MSmEi/eB+W+h30NGdqLJCziLDlp409jAfXbQm/4Yx7apLvEmkaYSrb5f/pfvYv1FEV1tS8/J7DgdHUAWo6gyGUUSZ
JgsyHcuJT7v9Tf0xwiFWOWL9WsWXa9fCKqTeYnYJhHlqfinZRnT/+jkz0OZ7YmXo6j4Hyms3RCOqenIX1W6gnIn+eQIkw==


## 2. add your SSH key to the ssh-agent

1. Ensure the ssh-agent is running

If you are using Git for Windows, you can use the "Auto-launching the ssh-agent" instructions in "Working with SSH key passphrases", or start it manually:
```
eval $(ssh-agent -s)
```

2. Add your SSH private key to the ssh-agent

Add your SSH private key to the ssh-agent. If you created your key with a different name, or if you are adding an existing key that has a different name, replace id_rsa in the command with the name of your private key file.

ssh-add ~/.ssh/id_rsa

## 3. Add the SSH key to your GitHub account.

- copy the public key
- go to https://github.com/settings/keys
- click `New SSH Key`
  - enter title, paste the key, click `Add SSH Key`


