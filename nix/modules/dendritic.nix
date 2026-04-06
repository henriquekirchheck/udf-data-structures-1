{ inputs, ... }:
{
  imports = [ inputs.flake-file.flakeModules.default ];

  flake-file = {
    inputs = {
      flake-file.url = "github:vic/flake-file";
      flake-parts.url = "github:hercules-ci/flake-parts";
      flake-parts.inputs.nixpkgs-lib.follows = "nixpkgs";
      import-tree.url = "github:vic/import-tree";
    };
    outputs = "inputs: inputs.flake-parts.lib.mkFlake { inherit inputs; } (inputs.import-tree ./nix)";
  };
}
