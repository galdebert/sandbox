
# 3-legged OAuth

3-legged OAuth describes the scenario for which OAuth was originally developed.

A **user** (guillaume.aldebert@autodesk.com)<br>
wants to give a<br>
**3rd party app** (my-cool-application...)<br>
access to a<br>
**server/api** (github.com, forge-api...)<br>
without sharing his credentials (i.e. username/password).

## original terminology

- user = resource owner
- client = third-party application

A **resource owner** wants to give a **client** access to a **server/api** without sharing his credentials (i.e. username/password).

## how it works

On a conceptual level it works in the following way:

- **3rd party app** has signed up to the **server** and got his client credentials (aka “consumer key and secret” or "client-id/client-secret") ahead of time
- **User** wants to give the **3rd party app** access to his protected resources on the **server**
- **3rd party app** retrieves the temporary credentials (aka “request token”) from the **server**
- **3rd party app** redirects the **user** to the **server**
- **user** grants the **3rd party app** access to his protected resources on the **server**
- **Server** redirects the user back to the **3rd party app**
- **3rd party app** uses the temporary credentials (“request token”) to retrieve the token credentials (aka “access token”) from the **server**
- **3rd party app** uses the token credentials (“access token”) to access the protected resources on the **server**

# 2-legged OAuth

2-legged OAuth, on the other hand, describes a typical client-server scenario, **without any user involvement**. An example for such a scenario could be a local Twitter client application accessing your Twitter account.

On a conceptual level 2-legged OAuth simply consists of the first and last steps of 3-legged OAuth:

- **3rd party app** has signed up to the **server** and got his client credentials (aka “consumer key and secret” or "client-id/client-secret") ahead of time
- **3rd party app** uses his client credentials (and empty token credentials) to access the protected resources on the server

Above I used Twitter as an example, though strictly speaking, they don’t use 2-legged OAuth, but a variant of it. They not only provide the client credentials but also the token credentials (see also Using one access token with OAuth).

As you have seen, 2-legged OAuth is nothing new, it is simply using OAuth in a different scenario than it was designed for. And hence you can use (almost?) all existing OAuth libraries for 2-legged OAuth, too.