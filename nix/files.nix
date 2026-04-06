{
  perSystem =
    { pkgs, ... }:
    {
      files.files = [
        {
          path_ = ".gitignore";
          drv = pkgs.writeText "gitignore" ''
            /result
            /.direnv
            /.cache
            /.zed
          '';
        }
        {
          path_ = ".envrc";
          drv = pkgs.writeText "direnv" "use flake";
        }
      ];
    };
}
