{
  flake.lib.toAction =
    pkgs: name: action:
    pkgs.runCommand name
      {
        buildInputs = [
          pkgs.action-validator
          pkgs.yj
        ];
        action = builtins.toJSON action;
        passAsFile = [ "action" ];
      }
      ''
        yj -jy < "$actionPath" > $out
        action-validator -v $out
      '';
}
