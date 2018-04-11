

https://developer.github.com/

A schema defines a GraphQL API's type system


It describes the complete set of possible data (objects, fields, relationships, everything) that a client can access. Calls from the client are validated and executed against the schema. A client can find information about the schema via introspection. A schema resides on the GraphQL API server. For more information, see "Discovering the GraphQL API."



Field


Argument
 set of key-value pairs attached to a specific field
 Mutations require an input object as an argument.


Implementation
A GraphQL schema may use the term implements to define how an object inherits from an interface.


Connection

Connections let you query related objects as part of the same call. With connections, you can use a single GraphQL call where you would have to use multiple calls to a REST API.


Node ------edge-------> Node
           +-cursor


====================================================
OAuth

Bearer Token

The **Bearer Token** or **Refresh token** is created for you by the **Authentication server**. When a user authenticates your application (client) the authentication server then goes and generates for you a Bearer Token (refresh token) which you can then use to get an **Access Token**.

The **Bearer Token** is normally some kind of secret value created by the authentication server. It isn't random; it is **created based upon the user giving you access and the client your application getting access**.

In order to **access an API** for example you need to use an **Access Token**. **Access tokens are short lived (around an hour)**. You use the **bearer token** to get a new **Access token**. To get an access token you send the Authentication server this bearer token along with your client id. **This way the server knows that the application using the bearer token is the same application that the bearer token was created for**. Example: I can't just take a bearer token created for your application and use it with my application it wont work because it wasn't generated for me.

Google Refresh token looks something like this: 1/mZ1edKKACtPAb7zGlwSzvs72PvhAbGmB8K1ZrGxpcNM

copied from comment: I don't think there are any restrictions on the bearer tokens you supply. Only thing I can think of is that its nice to allow more then one. For example a user can authenticate the application up to 30 times and the old bearer tokens will still work. oh and if one hasn't been used for say 6 months I would remove it from your system. It's your authentication server that will have to generate them and validate them so how it's formatted is up to you.


oauth_authorization.create: OAuth application (GraphQL API Explorer)


{
  __type(name: "Repository") {
    name
    kind
    description
    fields {
      name
    }
  }
}



{
  "data": {
    "__type": {
      "name": "Repository",
      "kind": "OBJECT",
      "description": "A repository contains the content for a project.",
      "fields": [
        {
          "name": "assignableUsers"
        },
        {
          "name": "codeOfConduct"
        },
        {
          "name": "collaborators"
        },
        {
          "name": "commitComments"
        },
        {
          "name": "createdAt"
        }
        ...
      ]
    }
  }
}


Authorized OAuth Apps
https://github.com/settings/applications


https://github.com/blog/1509-personal-api-tokens
You can now create your own personal API tokens for use in scripts and on the command line. Be careful, these tokens are like passwords so you should guard them carefully. The advantage to using a token over putting your password into a script is that a token can be revoked, and you can generate lots of them. Head on over to your settings to manage personal API tokens.

Creating a personal access token for the command line
https://help.github.com/articles/creating-a-personal-access-token-for-the-command-line/

https://github.com/settings/tokens/new
Personal access tokens function like ordinary OAuth access tokens. They can be used instead of a password for Git over HTTPS, or can be used to authenticate to the API over Basic Authentication.


# Using a token on the command line
Once you have a token, you can enter it instead of your password when performing Git operations over HTTPS.

For example, on the command line you would enter the following:

git clone https://github.com/username/repo.git
Username: your_username
Password: your_token
Personal access tokens can only be used for HTTPS Git operations. If your repository uses an SSH remote URL, you will need to switch the remote from SSH to HTTPS.

If you are not prompted for your username and password, your credentials may be cached on your computer. You can update your credentials in the Keychain to replace your old password with the token.



# authentification to use github API

https://developer.github.com/v3/#authentication

## Basic authentication

curl -u "username" https://api.github.com

## OAuth2 token (sent in a header)

curl -H "Authorization: token OAUTH-TOKEN" https://api.github.com

## OAuth2 token (sent as a parameter)

curl https://api.github.com/?access_token=OAUTH-TOKEN

Read more about OAuth2. Note that OAuth2 tokens can be acquired programmatically, for applications that are not websites.

## OAuth2 key/secret

curl 'https://api.github.com/users/whatever?client_id=xxxx&client_secret=yyyy'
This should only be used in server to server scenarios. Don't leak your OAuth application's client secret to your users.


# Authorization options for OAuth Apps

https://developer.github.com/apps/building-oauth-apps/authorization-options-for-oauth-apps/


GET https://api.github.com/user?access_token=...



# curl for windows

- install from chocolatey
- From http://curl.haxx.se/docs/caextract.html, Download the cacert.pem file.
- Place the curl.exe and the .pem file in the same directory. 
  - ie C:\ProgramData\chocolatey\lib\curl\tools\curl_x64
- Rename the cacert.pem file to curl-ca-bundle.crt
- Re-run curl.exe


# POSTMAN

