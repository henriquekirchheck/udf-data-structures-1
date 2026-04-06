{ inputs, ... }:
{
  flake-file.inputs.treefmt-nix = {
    url = "github:numtide/treefmt-nix";
    inputs.nixpkgs.follows = "nixpkgs";
  };
  imports = [ inputs.treefmt-nix.flakeModule ];

  flake-file.formatter = pkgs: pkgs.nixfmt;

  perSystem =
    { pkgs, ... }:
    {
      treefmt = {
        package = pkgs.treefmt;
        flakeCheck = true;
        flakeFormatter = true;
        projectRootFile = "flake.nix";

        settings = { };

        programs = {
          nixfmt.enable = true;
          statix.enable = true;
          deadnix.enable = true;
        };
      };
    };
}
