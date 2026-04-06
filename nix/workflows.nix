{ self, ... }:
{
  perSystem =
    { pkgs, ... }:
    let
      toAction = self.lib.toAction pkgs;
    in
    {
      files.files = [
        {
          path_ = ".github/workflows/check.yml";
          drv = toAction "gh-actions-workflow-check.yaml" {
            name = "Update Flake";
            on = {
              push.branches = [ "main" ];
              pull_request.types = [
                "opened"
                "reopened"
                "synchronize"
              ];
              repository_dispatch.types = [ "create-pull-request" ];
              workflow_dispatch = { };
            };
            jobs.check = {
              runs-on = "ubuntu-latest";
              steps = [
                {
                  name = "Checking out repository";
                  uses = "actions/checkout@v4";
                }
                {
                  name = "Installing and configuring the nix package manager";
                  uses = "cachix/install-nix-action@v31";
                  "with".extra_nix_config = "accept-flake-config = true";
                }
                {
                  name = "Setting up packages";
                  run = "nix profile install nixpkgs#nix-fast-build";
                }
                {
                  name = "Running `nix flake check`";
                  run = "nix-fast-build --skip-cached --no-nom";
                }
                {
                  name = "Running `nix build`";
                  run = "nix-fast-build --skip-cached --no-nom --flake \".#packages\"";
                }
                {
                  name = "Running `nix develop`";
                  run = "nix-fast-build --skip-cached --no-nom --flake \".#devShells\"";
                }
                {
                  name = "Checking flake inputs for stale & insecure nixpkgs versions";
                  uses = "DeterminateSystems/flake-checker-action@main";
                }
              ];
            };
          };
        }
        {
          path_ = ".github/workflows/update.yml";
          drv = toAction "gh-actions-workflow-update.yaml" {
            name = "Update Flake";
            on = {
              schedule = [ { cron = "30 6 * * *"; } ];
              workflow_dispatch = { };
            };
            jobs.update = {
              runs-on = "ubuntu-latest";
              steps = [
                {
                  name = "Checking out repository";
                  uses = "actions/checkout@v4";
                }
                {
                  name = "Installing and configuring the nix package manager";
                  uses = "cachix/install-nix-action@v31";
                  "with".extra_nix_config = "accept-flake-config = true";
                }
                {
                  name = "Updating flake.lock";
                  uses = "DeterminateSystems/update-flake-lock@main";
                  "with" = {
                    pr-title = "Automated action - Update flake.lock";
                    pr-labels = ''
                      dependencies
                      automated
                    '';
                  };
                }
              ];
            };
          };
        }
      ];
    };
}
