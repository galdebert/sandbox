

# reviewing-gitpitch-and-spectacle-two-presentation-solutions-for-developers

https://schneids.net/reviewing-gitpitch-and-spectacle-two-presentation-solutions-for-developers/

# GitPitch

GitPitch can export the presentation for offline use
You can add your own styles to GitPitch using CSS
GitPitch caches the presentation on the master branch for 180 seconds. For feature branches, it's 20 seconds. 
GitPitch has a presenter mode
Nitpicky, but I wish GitPitch would change the URL based on what slide I'm on. With GitPitch, you have to define custom navigation points to go to different slides. Spectacle just does this out of the box.

# remark

markdown-to-slides -h

Usage: C:\Dev\nodejs\node.exe C:\Users\guillaume\AppData\Roaming\npm\node_modules\markdown-to-slides\index.js file.md

Options:
  --title, -t           Generated page title
  --style, -s           Path to custom stylesheet                                                      [default: "C:\\Users\\guillaume\\AppData\\Roaming\\npm\\node_modules\\markdown-to-slides\\template\\style.css"]
  --script, -j          Path to custom javascript
  --template, -l        Path to custom mustache template                                               [default: "C:\\Users\\guillaume\\AppData\\Roaming\\npm\\node_modules\\markdown-to-slides\\template\\template.html"]
  --help, -h            This screen
  --output-file, -o     Path to output file (stdout if not specified)
  --document-mode, -d   Generate slides from a document without slide separators (---) or annotations  [boolean]
  --watch, -w           Watch mode                                                                     [boolean]
  --level               Heading level to use as new slides (for example 3 is ###)                      [default: 3]
  --include-remark, -i  Include Remark sources (around 850kB) into the generated document              [boolean]
