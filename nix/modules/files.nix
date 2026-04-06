{ inputs, ... }:
{
  flake-file.inputs.files.url = "github:mightyiam/files";
  imports = [ inputs.files.flakeModules.default ];

  perSystem =
    { config, ... }:
    {
      packages.write-files = config.files.writer.drv;
    };
}
