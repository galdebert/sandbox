# package-lock.json

- `npm init` creates a simple `package.json`
- `npm outdated` check the registry to see if any (or, specific) installed packages are currently outdated.
  - wanted is the maximum version of the package that satisfies the semver range 
  - latest is the version of the package tagged as latest in the registry

https://docs.npmjs.com/files/package-lock.json

package-lock.json is automatically generated for any operations where npm modifies either the `node_modules` tree, or `package.json`.
It describes the exact tree that was generated, such that subsequent installs are able to generate identical trees, regardless of intermediate dependency updates.

https://medium.com/@Quigley_Ja/everything-you-wanted-to-know-about-package-lock-json-b81911aa8ab8

Starting from npm 5.1.0, `package.json` overrules the package-lock.json.

But anyways, sounds like `npm install` must be called after a manual change to `package.json`. So `package-lock.json` will be in sync with `package.json`.

## regen package-lock.json

https://stackoverflow.com/questions/46653833/is-there-a-way-to-force-npm-to-generate-package-lock-json

By default, package-lock.json is updated whenever you run `npm install`.

Anytime one changes manually package.json

Be careful: the generation of package-lock.json depends on what you have in your node_modules folder when ypu run `npm install`

## package-lock.json line endings 

https://stackoverflow.com/questions/32490412/how-can-i-configure-npm-to-use-windows-style-line-endings-in-package-json


